#define PY_SSIZE_T_CLEAN
#include "Python.h"

/**
 * void print_python_string - print some basic info about Python float objects.
 * @p: pointer to a Python object (presumably of subtype PyList_Type)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_string(PyObject *p)
{
    (void)p;
}
