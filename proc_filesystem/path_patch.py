#!/usr/bin/python3
"""A LITTLE EXPERIMENT I WANTED TO INCLUDE"""
import io

from pathlib import PosixPath
from platform import python_version_tuple


class PathPatch:
    """FOUR MISSING METHODS I WANT TO BE ABLE TO BACKORT IF NEEDED"""
    def read_bytes(self):
        """
        Open the file in bytes mode, read it, and close the file.
        """
        with self.open(mode='rb') as f:
            return f.read()

    def read_text(self, encoding=None, errors=None):
        """
        Open the file in text mode, read it, and close the file.
        """
        with self.open(mode='r', encoding="utf-8", errors=errors) as f:
            return f.read()

    def write_bytes(self, data):
        """
        Open the file in bytes mode, write to it, and close the file.
        """
        # type-check for the buffer interface before truncating the file
        view = memoryview(data)
        with self.open(mode='wb') as f:
            return f.write(view)

    def write_text(self, data, encoding=None, errors=None, newline=None):
        """
        Open the file in text mode, write to it, and close the file.
        """
        if not isinstance(data, str):
            raise TypeError('data must be str, not %s' %
                            data.__class__.__name__)
        encoding = io.text_encoding(encoding)
        with self.open(
            mode='w',
            encoding=encoding,
            errors=errors,
            newline=newline
        ) as f:
            return f.write(data)


INSTALL_NEEDS_PATCH = (int(python_version_tuple()[1]) <= 4)

if INSTALL_NEEDS_PATCH:

    missing_functions = {
        name: func_obj for name, func_obj in vars(PathPatch).items()
        if "__" not in name
    }
    for name, function in missing_functions.items():
        setattr(PosixPath, name, function)

Path = PosixPath
