#include <stdio.h>

int main(void)
{
    int result;

    asm volatile (
        "mov $2, %%eax\n\t"  // Move the value 2 into the EAX register
        "add $2, %%eax\n\t"  // Add 2 to the value in the EAX register
        "mov %%eax, %0\n\t"  // Move the value in the EAX register to 'result'
        : "=r"(result)       // Output constraint to bind 'result' to EAX register
        :                    // No input constraints
        : "%eax"             // Clobbered register (EAX)
    );

    printf("The result is: %d\n", result);

    return 0;
}
