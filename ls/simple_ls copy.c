void empty_asm(void)
{
    asm volatile (
        ""
    );
}

/**
 * main - the entry point for the program
 *
 * Return: returns 0
*/
int main(void)
{
	empty_asm();

	return (0);
}
