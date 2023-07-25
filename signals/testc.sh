#!/usr/bin/bash

CC="gcc"
FLAGS="-Wall -Wextra -Werror -pedantic -g"

TASK_FILE=$1
FIRST_CHAR="${TASK_FILE:0:1}"
SRC_FILES="$(find . -maxdepth 1 -type f -name "${FIRST_CHAR}*")"
EXECUTABLE="${TASK_FILE%.*}"

if [[ (! -f "$TASK_FILE") ]]; then
    echo "USAGE: PROJECT SOURCE FILE IN DIRECTORY"
    exit 1
fi

$CC $FLAGS $SRC_FILES -o $EXECUTABLE
