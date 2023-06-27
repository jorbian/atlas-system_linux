#!/usr/bin/python3
"""REPLACE A STRING IN THE HEAP OF A GIVEN PROCESS --
USAGE: ./read_write_heap.py <PID> <search str> <replacement str>"""

import sys
import re

from process import Process


def read_write_heap(pid, target, replacement):
    """THE MAIN ATTRACTION FOR TODAY"""

    def replace_string(file_obj, addresses):
        """ABUSES THE FACT THAT, AS A NESTED FUNCTION PARENTS LOCALS ARE IN
        ITS SCOPE"""
        start = addresses[0]
        end = addresses[1]

        file_obj.seek(start)
        heap_seg = file_obj.read(end - start)

        position = heap_seg.find(target.encode())

        if position > -1:
            target_location = start + position
            file_obj.seek(target_location)
            file_obj.write(replacement.encode() + b'\x00')

    find_heap = "^([0-9a-f]+)-([0-9a-f]+).*\\[heap]$"

    process = Process(pid)

    if not process.exists:
        print(
            "ERROR: PROCESS WITH PID {} WAS NOT FOUND.".format(pid),
            file=sys.stderr
        )
        exit(1)
    heap_location = process.find_memory_address(find_heap)

    process.visit_memory_segment(heap_location, replace_string)


if __name__ == "__main__":
    if (len(sys.argv) < 4 or not sys.argv[1].isdigit()):
        print(__doc__, file=sys.stderr)
        exit(1)

    read_write_heap(
        pid=sys.argv[1],
        target=sys.argv[2],
        replacement=sys.argv[3]
    )
