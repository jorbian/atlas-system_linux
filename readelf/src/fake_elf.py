#!/usr/bin/env python3

import sys
import subprocess

def run_fake_program(filename="a.out", program="hls", command_string="ls"):
    """RUNS RUN OF THE TWO PROGRAMS FOR THS PROJECT I HAVEN'T WRITTEN YET..."""
    x = subprocess.Popen(
        command_string.format(filename).split(" "),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    output_message = (x.stderr.read() or x.stdout.read()).decode()
    error_happened = not (output_message.find(program[1:]))

    if (error_happened):
        output_message = ("./{}{}".format(program[0], output_message))
        print_to, exit_stat = sys.stderr, 1
    else:
        print_to, exit_stat = sys.stdout, 0

    print(output_message, file=print_to, end="")

    exit(exit_stat)

filename = sys.argv[1] if len(sys.argv) >= 2 else ""

