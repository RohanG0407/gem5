#include <stdio.h>
#include <gem5/m5ops.h>

#define N 20

int main(int argc, char *argv[]) {
    long long result = 1;
    long long factor = 2;

    asm volatile("isb");
    asm volatile("msr DIT, #1");
    result *= factor;
    result *= factor;
    result *= factor;
    result *= factor;
    result *= factor;
    asm volatile("msr DIT, #0");

    long long dividend = 1048576;
    long long divisor = 2;

    asm volatile("msr DIT, #1");
    dividend /= divisor;
    dividend /= divisor;
    dividend /= divisor;
    dividend /= divisor;
    dividend /= divisor;
    asm volatile("msr DIT, #0");


    printf("Mult Final result: %lld\n", result);
    printf("Div Final result: %lld\n", dividend);

    return 0;
}
