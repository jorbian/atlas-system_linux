#!/usr/bin/env python3

from pathlib import Path

import re

file = Path("data")

data = file.read_text().split("\n")[1:]

for line in data:
    colon = line.index(":")
    non_space = re.search(r'\S',line).start()
    num_spaces = len(line[colon: non_space])

    print(line[:colon], num_spaces)