#ifndef MYPY_H
#define MYPY_H

#include "Python.h"

#define PY_SSIZE_T_CLEAN

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);
void print_python_string(PyObject *p);
void print_python_int(PyObject *p);

#endif
