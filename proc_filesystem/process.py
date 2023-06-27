#!/usr/bin/python3
"""OBJECT MODEL FOR MANIPULATING PROCESS THROUGH /proc FILESYSTEM"""

import re

from path_patch import Path


class Process:
    """THE OBJECT MODEL IN QUESTION"""
    @staticmethod
    def pull_active_procs():
        """RETURNS GENERATOR WITH PATH OBJECTS OF ALL PROC FOLDERS"""
        return (Path("/proc").glob('[0-9]*'))

    @staticmethod
    def sanitize_mem_addresses(address_pair):
        """PREPARES MEM ADDRESSES FOR USE IN TRANSVERSING MEMORY"""
        address_pair = tuple(int(addr, 16) for addr in address_pair)
        return (address_pair[0], address_pair[1])

    @classmethod
    def proccess_exists(cls, pid):
        return (pid in (proc.name for proc in cls.pull_active_procs()))

    def __init__(self, pid):
        self.pid = pid
        self.path_obj = Path("/proc/{}".format(pid))
        self.exists = Process.proccess_exists(pid)

    def find_memory_address(self, pattern):
        """FINDS A MEMORY ADDRESS PAIR BASED ON REGEX"""
        maps_file_obj = Path(
            "{}/maps".format(
                self.path_obj.resolve()
            )
        )
        maps_data = maps_file_obj.read_text()
        search_obj = re.search(pattern, maps_data, flags=re.MULTILINE)

        if (search_obj is not None):
            return Process.sanitize_mem_addresses(search_obj.groups())
        else:
            return ()

    def visit_memory_segment(self, addresses, agenda):
        """PULL UP A SEGMENT OF MEMORY USED BY PROCESS AND DO WHATEVER"""
        mem_file_path = "{}/mem".format(self.path_obj.resolve())

        with open(mem_file_path, "r+b") as file:
            agenda(file, addresses)
