#!/usr/bin/python3
"""REPLACE A STRING IN THE HEAP OF A GIVEN PROCESS --
USAGE: ./read_write_heap.py <PID> <search str> <replacement str>"""

import sys
import re

from pathlib import Path
from processlib import ProcessPath


ERROR_MESSAGES = {
    "bad_input": "PID MUST BE VALID PROCESS ID, FOLLOWED BY TWO STRINGS."
}


def read_write_heap(pid, target, replacement):
    """REPLACE A STRING IN THE HEAP OF GIVEN PROCESS"""
    target_process = ProcessPath(pid)

    bad_input = (
        (not target_process.is_valid_process),
        (not target or not replacement)
    )
    if (any(bad_input)):
        raise ValueError(ERROR_MESSAGES["bad_input"])

    search_expression = re.compile(
        "^([0-9a-f]{12})-([0-9a-f]{12})\s.*\[heap\]",
        flags=re.MULTILINE
    )
    heap_start, heap_end = target_process.find_address_range(
        search_expression
    )
    target_process.edit_value_in_range(
        addr_range={
            "start": heap_start,
            "end": heap_end
        },
        target_info={
            "target": target,
            "replacement": replacement
        }
    )


if __name__ == "__main__":
    if (len(sys.argv) < 4 or not sys.argv[1].isdigit()):
        print(__doc__, file=sys.stderr)
        exit(1)

    read_write_heap(
        pid=sys.argv[1],
        target=sys.argv[2],
        replacement=sys.argv[3]
    )
