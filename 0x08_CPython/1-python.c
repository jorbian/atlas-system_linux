#include "myPy.h"

/**
 * print_python_list - print basic info about Python list
 * @p: pointer to a Python object (presumably of subtype PyList_Type)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_list(PyObject *p)
{
	Py_ssize_t i, length;

	if (PyList_Check(p) == 0)
		return;
	else
		printf("[*] Python list info\n");

	length = PyList_Size(p);

	printf("[*] Size of the Python List = %lu\n", length);
	printf("[*] Allocated = %lu\n", Py_SIZE(p));

	for (i = 0; i < length; i++)
	{
		printf(
			"Element %lu: %s\n",
			i,
			(PyList_GetItem(p, i)->ob_type)->tp_name
		);
	}
}