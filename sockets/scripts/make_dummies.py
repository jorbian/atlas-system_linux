#!/usr/bin/python3

from pathlib import Path

TEMPLATE_NAME = "task4.c"

PROJECT_FOLDER = Path(".")
PROJECT_FILES = PROJECT_FOLDER.glob("*")

TEMPLATE_OBJ = next((x for x in PROJECT_FILES if TEMPLATE_NAME in x.name), Path())

print(TEMPLATE_OBJ)