#define NULL (void *)0


void simple_ls(void) {
	const char *filename = "/bin/ls";
	const char *argv[] = {filename, NULL};
	const char *envp[] = {NULL};

	asm volatile (
		"movq $59, %%rax\n"
		"movq %0, %%rdi\n"
		"movq %1, %%rsi\n"
		"movq %2, %%rdx\n"
		"syscall\n"
		:
		: "r"(filename), "r"(argv), "r"(envp)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
}

int main() {
	simple_ls();
	return 0;
}
