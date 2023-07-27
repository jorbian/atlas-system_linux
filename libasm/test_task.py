#!/usr/bin/python3

import sys

from pathlib import Path

input_file = Path(sys.argv[1])

intermediate_files = {
    "driver_src": f"{input_file.name[0]}-main.c",
    "driver_obj": f"{input_file.name[0]}-main.o",
    "assembly_obj": f"{input_file.stem}.o",
    "executable": input_file.stem
}

print(interpediate_files)

command_lines = {
    "compile_main": [
        "-Wall", "-Wextra", "-Werror" "-pedantic", "-g3" "-c", "-o", "XX-main.o", "XX-main.c"
    ],
    "create_asm_obj": ["nasm", "-f", "elf64", "-o", "1-strcmp.o", sys.argv[1]],
    "create_executable": ["gcc", "-o", "1-strcmp", "1-main.o", "1-strcmp.o"]
}