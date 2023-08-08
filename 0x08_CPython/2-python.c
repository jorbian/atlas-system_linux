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
	Py_ssize_t size;

	unsigned int i;

	printf("[.] bytes object info\n");
	if (!PyBytes_CheckExact(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = PyBytes_Size(p);

	printf("  size: %ld\n", size);
	printf("  trying string %s\n", PyBytes_AsString(p));

	if (size >= 10)
		size = 10;
	else
		size++;

	printf("  first %lu bytes:", size);
	for (i = 0; i < size; i++)
		printf(" %02x", PyBytes_AsString(p)[i] & 0xff);
	putchar('\n');
}
