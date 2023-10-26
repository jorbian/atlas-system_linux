#!/usr/bin/python3

from pathlib import Path

execname = "todo_api_0"
source = "./scripts/task4.py"

source_obj = Path(source)
source_code = Path(source).read_text()

Path(execname).write_text(source_code)

Path(execname).chmod(0o777)