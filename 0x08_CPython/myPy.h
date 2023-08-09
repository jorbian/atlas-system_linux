#ifndef MYPY_H
#define MYPY_H

#include "Python.h"
#include <string.h>

#define PY_SSIZE_T_CLEAN
#define MAX_BYTES 10

#define BS_AS_STRING(op) ((PyBytesObject *)op)->ob_sval
#define GET_ITEM(op, i) ((((PyListObject *)op)->ob_item[i]))
#define SIZE(op) (( _PyVarObject_CAST(op))->ob_size)

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);
void print_python_string(PyObject *p);
void print_python_int(PyObject *p);

#endif
