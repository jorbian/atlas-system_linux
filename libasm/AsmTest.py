#!/usr/bin/python3

import sys

from pathlib import Path

class AsmTest:
    """REPRESENTATION OF PARTICULAR TEST OF AN ASSEMBLY SRC FILE CONTAINING
    SINGLE SUBROUTINE MEANT TO BE CALLED AS C FUNC IN DRIVER CODE 'X-main.c'"""
    FILENAMES = (
        "driver_obj", "driver_src", "asm_obj", "asm_src", "executable"
    )
    COMMAND_LINES = {
        "create_driver_obj": "gcc -Wall -Wextra -Werror -pedantic -g3 -c -o driver_obj driver_src",
        "create_asm_obj": "nasm -f elf64 -o asm_obj asm_src",
        "create_executable": "gcc -o executable driver_obj asm_obj"
    }

    def __init__(self, filename):
        self.file_obj = Path(filename)
        self.filenames = self.generate_filenames()

    def generate_filenames(self):
        """POPULATES A DICTIONARY CONTAINING ALL THE FILE NAMES NEEDED IN TEST"""
        return {
            "driver_src": f"{self.file_obj.name[0]}-main.c",
            "driver_obj": f"{self.file_obj.name[0]}-main.o",
            "asm_src": self.file_obj.name,
            "asm_obj": f"{self.file_obj.stem}.o",
            "executable": self.file_obj.stem
        }
    
    def fill_commands_in(self):
        """ITERATES OVER COMMANDS LINE BY LINE TO FILL-IN COMMAND STRINGS"""
        command_lines = AsmTest.COMMAND_LINES

x = AsmTest(sys.argv[1])

print(x.filenames)