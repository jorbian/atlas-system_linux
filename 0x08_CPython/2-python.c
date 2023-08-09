#include "myPy.h"

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

	if (size > MAX_BYTES)
		size = MAX_BYTES;
	else
		size++;

	printf("  first %lu bytes:", size);

	for (i = 0;; i++)
	{
		if (i > MAX_BYTES || i == size)
			break;

		printf(" %02x", PyBytes_AsString(p)[i] & 0xff);
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
		current_item = GET_ITEM(p, i);

		strcpy(type, current_item->ob_type->tp_name);

		printf("Element %ld: ", i);

		if ((strcmp(type, "bytes") == 0))
		{
			printf("bytes\n");
			print_python_bytes((PyObject *)current_item);
			continue;
		}
		printf("%s\n", type);
	}
}
