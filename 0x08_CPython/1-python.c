#include "myPy.h"

static PyObject *get_item(PyObject *op, Py_ssize_t i);

/**
 * print_python_list - print basic info about Python list
 * @p: pointer to a Python object (presumably of subtype PyList_Type)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_list(PyObject *p)
{
	Py_ssize_t i, length;
	char type[255];

	if (!PyList_Check(p))
		return;

	length = PyList_Size(p);

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %lu\n", length);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < length; i++)
	{
		strcpy(type, get_item(p, i)->ob_type->tp_name);

		printf("Element %lu: %s\n", i, type);
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
