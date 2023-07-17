#!/usr/bin/bash

if [ ! -e "$1" ] || [[ $1 != *.asm ]]; then
    echo "PLEASE PROVIDE THE NAME OF .asm SOURCE FILE"
fi

BASENAME="${1%.*}"

nasm -f elf32 "$BASENAME.asm" -o "$BASENAME.o"
ld -m elf_i386 "$BASENAME.o" -o $BASENAME

./"$BASENAME"

echo $?

rm "$BASENAME.o"
rm $BASENAME