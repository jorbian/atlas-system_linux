#!/usr/bin/env python3

import os

from pathlib import Path

new_ext = ".h"

header_files = [
    str(x.resolve()) for x in Path(".").rglob("*.hdr")
]
new_names = [f"{(x[:x.index('.')])}{new_ext}" for x in header_files]

for file, name in zip(header_files, new_names):
    Path(file).rename(Path(name))