/**
 * simple_ls - a non hardend version of what we're doing for task one
 *
 * Description: TBA
*/
void simple_ls(void)
{
	const char *argv[] = {"/bin/sh", "-c", "ls", (void *)0};

	asm volatile (
		"mov $0, %%rax\n\t" /* Set the rax register to 0 */
		"mov $0x3b, %%eax\n\t" /*Set lower 32 bts of rax to 0x3b (sys_execve)*/
		"mov %0, %%rdi\n\t" /* Set the rdi register to the shell path address */
		"mov %1, %%rsi\n\t" /* Set the rsi register to the argv array address */
		"xor %%rdx, %%rdx\n\t" /* Set rdx register to 0 */
		"syscall\n\t" /* Call the Linux system call */
		:
		: "r"("/bin/sh"), "r"(argv)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
}

/**
 * main - the entry point for the program
 *
 * Return: returns 0
*/
int main(void)
{
	simple_ls();

	return (0);
}
