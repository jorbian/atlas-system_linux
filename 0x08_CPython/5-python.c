#include "myPy.h"

/**
 * print_python_int - print Python integers.
 * @p: pointer to a Python object (presumably an integer)
 *
 * Return: Just returns void since we're not doing anything to it.
*/
void print_python_int(PyObject *p)
{
    Py_ssize_t size, magnitude, i, num;
    digit *digits;

	size = ((PyVarObject *)p)->ob_size;
    magnitude = labs((long)size);
	digits = ((PyLongObject *)p)->ob_digit;
	num = 0;

	setbuf(stdout, NULL);

	if (!PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}

	if ((magnitude == 3 && digits[2] >= 16) || magnitude > 3)
	{
		printf("C unsigned long int overflow\n");
		return;
	}

	for (i = 0; i < magnitude; i++)
		num += digits[i] * (1L << (i * PyLong_SHIFT));

	if (size < 0)
		putchar('-');

	printf("%lu\n", num);
}
