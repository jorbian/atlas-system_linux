#!/usr/bin/env bash

TASK_FILE=$1
LIB_NAME="PyList"
OUTFILE="lib$LIB_NAME.so"

ERROR_MSG="$(ls $1 2>&1 > /dev/null)"

if [[ -n "$ERROR_MSG" ]]; then
	echo "${ERROR_MSG/ls/$0}" >> /dev/stderr
	exit 1
fi

TASK_NUM="${TASK_FILE:0:1}"
FILE_EXT="${TASK_FILE##*.}"

# The most useful thing I learned --
# 1) negation in a glob [!$NOT_THIS]
DRIVER="$(ls $TASK_NUM*[!.$FILE_EXT])"
if [ $? -eq 1 ]; then
    echo "$0: missing driver code"
    exit 1
fi

gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,$LIB_NAME \
    -o $OUTFILE -fPIC -I/usr/include/python3.10 $TASK_FILE

if [ $? -eq 0 ]; then
    ./$DRIVER
    rm $OUTFILE
fi
