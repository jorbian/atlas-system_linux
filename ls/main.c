#include <stdio.h>
#include <unistd.h>

void execute_system(const char* command)
{
	const char* shell = "/bin/sh";
	const char* argv[] = {shell, "-c", command, NULL};
	
	asm volatile (
		"mov $0, %%rax\n\t" /* Set the rax register to 0 */
		"mov $0x3b, %%eax\n\t" /* Set the lower 32 bits of rax to 0x3b (sys_execve) */
		"mov %0, %%rdi\n\t" /* Set the rdi register to the shell path address */
		"mov %1, %%rsi\n\t" // Set the rsi register to the argv array address
		"xor %%rdx, %%rdx\n\t" /* Set rdx register to 0 */
		"syscall\n\t" /* Call the Linux system call */
		:
		: "r"(shell), "r"(argv)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
}

int main()
{
	execute_system("ls"); // Execute the command (output will be captured by the pipe)

	return (0);
}
