#!/usr/bin/python3

import sys

from pathlib import Path

class ProjectTask:

    def __init__(self, filename):
        self.asm_file = Path(filename)