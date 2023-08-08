#define PY_SSIZE_T_CLEAN
#include "Python.h"

/**
 * print_python_bytes - print some basic info about Python bytes objects.
 * @p: pointer to a Python object (presumably of subtype PyList_Type)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_bytes(PyObject *p)
{
    printf("[.] bytes object info\n");
    if (!PyBytes_CheckExact(p))
    {
        printf("[ERROR] Invalid Bytes Object\n");
        return;
    }
    printf("  size: %ld\n", PyBytes_Size(p));
    printf("  trying string %s\n", PyBytes_AsString(p));
}
