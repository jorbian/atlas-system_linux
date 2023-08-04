#!/usr/bin/env python3

import sys
import subprocess

def run_fake_program(filename="a.out", program="hls", command_string="ls"):
    """RUNS RUN OF THE TWO PROGRAMS FOR THS PROJECT I HAVEN'T WRITTEN YET..."""
    command_args = command_string.format(filename).split(" ")

    x = subprocess.Popen(
        command_args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        bufsize=0,
        text=True
    )
    output_message, error_message = x.communicate()
    if x.returncode != 0:
        output_message = error_message

    error_happened = not (output_message.find(program[1:]))

    if error_happened:
        output_message = ("./{}{}".format(program[0], output_message))
        print_to, exit_stat = sys.stderr, 1
    else:
        print_to, exit_stat = sys.stdout, 0

    print(output_message, file=print_to, end="")  # Decode output_message if using text mode

    exit(exit_stat)

filename = sys.argv[1] if len(sys.argv) >= 2 else ""

