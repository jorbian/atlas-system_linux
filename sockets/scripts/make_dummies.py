#!/usr/bin/python3

from pathlib import Path

TEMPLATE_NAME = "task4.c"
PROJECT_FOLDER = Path(".")

project_files = PROJECT_FOLDER.glob("*")

template_obj = next((x for x in project_files if TEMPLATE_NAME in x.name), Path())

start_num = template_obj.stem[-1]
filename = f'{template_obj.stem[:-1]}{template_obj.suffix}'
print(filename)