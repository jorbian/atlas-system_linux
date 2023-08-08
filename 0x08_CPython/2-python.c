#include "myPy.h"

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
	printf("  trying string: %s\n", PyBytes_AsString(p));

	if (size >= 10)
		size = 10;
	else
		size++;

	printf("  first %lu bytes:", size);
	for (i = 0; i < size; i++)
		printf(" %02x", PyBytes_AsString(p)[i] & 0xff);
	putchar('\n');
}

/**
 * print_python_list - print basic info about Python list
 * @p: pointer to a Python object (presumably of subtype PyList_Type)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_list(PyObject *p)
{
	Py_ssize_t i, length;

	if (!PyList_Check(p))
		return;

	length = PyList_Size(p);

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", length);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < length; i++)
	{
		printf(
			"Element %lu: %s\n",
			i,
			(((PyListObject *)p)->ob_item[i]->ob_type)->tp_name
		);
	}
}
