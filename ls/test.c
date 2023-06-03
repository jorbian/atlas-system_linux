#include <stdio.h>

int main(void)
{
    int result;

    asm volatile (
        "mov $2, %%eax\n\t"
        "add $2, %%eax\n\t"
        "mov %%eax, %0\n\t" 
        : "=r"(result)
        : 
        : "%eax"            
    );

    printf("The result is: %d\n", result);

    return 0;
}
