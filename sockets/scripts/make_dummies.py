#!/usr/bin/python3

from pathlib import Path

PROJECT_FOLDER = Path(".").glob("*")

print(list(PROJECT_FOLDER))