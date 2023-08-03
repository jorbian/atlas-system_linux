#!/usr/bin/env python3

import sys

from pathlib import Path
from subprocess import run

nm = run(["nm", "-p", sys.argv[1]], capture_output=True).stdout

nm_output = nm.decode()

print(nm_output)