#!/bin/sh

TEST_FILE=${1:-"test.c"}
EXEC_NAME="${TEST_FILE%.*}"
STATIC_LIB=${2:-"./lib/libLIEF.a"}

gcc -Iinc -o $EXEC_NAME $TEST_FILE $STATIC_LIB -lm -lstdc++
if [ $? -eq 1 ]; then
    exit 1
fi

./$EXEC_NAME

rm $EXEC_NAME