#!/usr/bin/python3

from pathlib import Path

TEMPLATE_NAME = "task4.c"
PROJECT_FOLDER = Path(".")

project_files = PROJECT_FOLDER.glob("*")

template_obj = next((x for x in project_files if TEMPLATE_NAME in x.name), Path())

print(template_obj)