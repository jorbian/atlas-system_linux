#include "myPy.h"

static PyObject *get_item(PyObject *op, Py_ssize_t i);

/**
 * print_python_bytes - print some basic info about Python bytes objects.
 * @p: pointer to a Python object (presumably of subtype PyList_Type)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_bytes(PyObject *p)
{
	Py_ssize_t i, size;

	char *bytes_string;

	printf("[.] bytes object info\n");

	if (!PyBytes_CheckExact(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	size = PyBytes_Size(p);
	bytes_string = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", bytes_string);
	printf("  first %lu bytes:", size);

	for (i = 0; i < 11; i++)
	{
		printf(" %02x", PyBytes_AsString(p)[i] & 0xff);

		if (i >= size)
			break;
	}
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
	PyObject *current_item;
	char type[255];

	if (!PyList_Check(p))
		return;

	length = PyList_Size(p);

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", length);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < length; i++)
	{
		current_item = get_item(p, i);

		strcpy(type, current_item->ob_type->tp_name);

		printf("Element %ld: ", i);

		if ((strcmp(type, "str") == 0) || (strcmp(type, "bytes") == 0))
		{
			printf("bytes\n");
			print_python_bytes((PyObject *)current_item);
			continue;
		}
		printf("%s\n", type);
	}
}

/**
 * get_item - just a copy of a forbidden function sans error checks
 * @op: pointer to the list object
 * @i: the length
 *
 * Return: pointer to whatever's in the list (as object)
*/
static PyObject *get_item(PyObject *op, Py_ssize_t i)
{
	return ((((PyListObject *)op)->ob_item[i]));
}
