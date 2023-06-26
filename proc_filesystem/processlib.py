#!/usr/bin/python3
"THIS IS THE CEREMONIAL DOCUMENTATION"
import csv
import os
import re

from pathlib import Path, _PosixFlavour


class ProcessPath(Path):
    """
    EXTENSION OF pathlib.Path OBJECT FROM STANDARD LIBRARY TO TAKE ADVANTAGE
    OF MANIPULATION OF POSIX PROCESSES VIA /proc FILESYSTEM.
    """
    _flavour = _PosixFlavour()   # NEEDED TO INHERIT FROM PATH
    _PATH_TEMP = "/proc/{}"
    _DEFAULT_ADDRESS_SEARCH = re.compile(
        "^([0-9a-f]{12})-([0-9a-f]{12})",
    )

    # AN IMPORTANT THING TO REALIZE THAT I DIDN'T KNOW BEFORE I DID THIS:
    # THERE IS A HUGE DIFFERENCE BETWEEN __init__ and __new__. THERE IS REALLY
    # NOT MUCH YOU SHOULD BE DOING, NORMALLY, IN __init__ BESIDES LITERALLY
    # WHAT IT SAYS ON THE TIN -- INITALIZING STUFF -- ESPECIALLY WHEN YOU HAVE
    # A BUNCH OF STUFF THAT NEEDS TREATED AS ARRIBUTES INSTEAD OF PROPERTIES.
    def __init__(self, initializer_val):
        """INITIALIZES OBJECT PROPERTIES AND ATTRIBUTES"""
        super().__init__()

        self.is_valid_process = (
            lambda x: x.exists() and x.parts[1] == 'proc'
        )(self)

    def __new__(cls, initializer_val):
        """CREATES PATH OBJECT BASED ON INITIALIZER VALUE"""
        init_scenarios = (
            (
                (lambda x: isinstance(x, Path)),
                (lambda x: x)
            ),
            (
                (lambda x: isinstance(x, int)),
                (lambda x: ProcessPath._PATH_TEMP.format(str(x)))
            ),
            (
                (lambda x: isinstance(x, str) and os.path.exists(x)),
                (lambda x: x)
            ),
            (
                (lambda x: isinstance(x, str) and x.isdigit()),
                (lambda x: ProcessPath._PATH_TEMP.format(x))
            )
        )
        selected_protocol = None

        for scenario, protocol in init_scenarios:
            if scenario(initializer_val):
                selected_protocol = protocol
                break

        if selected_protocol:
            obj = super().__new__(cls, selected_protocol(initializer_val))
            return obj
        else:
            raise ValueError

    def find_address_range(self, search_expr=_DEFAULT_ADDRESS_SEARCH):
        """SEARCHES PROCESS'S MAP FILE TO FIND ADDRESS RANGE MATCHING EXPR"""
        map_file_obj = Path(
            "{}/maps".format(
                self.resolve()
            )
        )
        with open(str(map_file_obj.resolve()), "r") as file:
            maps_file_contents = (
                file.read() if map_file_obj.exists else ""
            )
        search_results = re.search(
            search_expr,
            maps_file_contents
        )
        return (
            search_results.groups() if search_results else ("", "")
        )

    def edit_value_in_range(self, addr_range, target_info):
        "THIS IS THE CEREMONIAL DOCUMENTATION"
        addr_range = {
            key: int(value, 16) for (key, value) in addr_range.items()
        }
        print(addr_range)
        print(target_info)
        start = addr_range.get("start")
        end = addr_range.get("end")

        mem_file_obj = Path(
            "{}/mem".format(
                self.resolve()
            )
        )
        try:
            with open(str(mem_file_obj.resolve()), "r+b") as file:
                file.seek(start)
                heapy = file.read(end - start)
                position = heapy.find(target_info["target"].encode())
                if position > -1:
                    location = start + position
                    file.seek(location)
                    file.write(target_info["target"].encode() + b'\x00')
                else:
                    exit
        except Exception as excepts:
            print(excepts)
            exit
