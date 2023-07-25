#!/usr/bin/bash

CC="gcc"
FLAGS="-Wall -Wextra -Werror -pedantic -g"

SRC_FILE=$1
FIRST_CHAR="${SRC_FILE:0:1}"
DRIVER="${FIRST_CHAR}-main.c"
EXECUTABLE="${SRC_FILE%.*}"

if [[ (! -f "$SRC_FILE") || (! -f "$DRIVER") ]]; then
    echo "USAGE: PROJECT SOURCE FILE IN DIRECTORY"
    exit 1
fi

$CC $FLAGS $SRC_FILE $DRIVER -o $EXECUTABLE
