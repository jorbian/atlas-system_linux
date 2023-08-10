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
	setbuf(stdout, NULL);

	printf("[.] string object info\n");

	if (PyUnicode_Check(p) == 0)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}

	if (((PyASCIIObject *)p)->state.ascii)
		printf("  type: compact ascii\n");
	else
		printf("  type: compact unicode object\n");

	printf(
        "  length: %ld\n  value: %ls\n",
        ((PyASCIIObject *)p)->length,
        PyUnicode_AS_UNICODE(p)
    );
}
