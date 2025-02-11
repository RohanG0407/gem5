#include <stdio.h>
#include <gem5/m5ops.h>

#define N 20

int main(int argc, char *argv[]) {
    long long result = 1;
    long long factor = 2;

    for (int i = 0; i < N * 100; i++) {
      asm volatile("msr DIT, #1");
      //asm volatile("ISB");
      result = 1;
      for (int j = 0; j < N; j++) {
          result *= factor;
      }
      asm volatile("msr DIT, #0");
      //asm volatile("ISB");
    }

    printf("Mult Final result: %lld\n", result);

    long long dividend = 1048576;
    long long divisor = 2;

    for (int i = 0; i < N * 100; i++) {
      asm volatile("msr DIT, #1");
      //asm volatile("ISB");
      dividend = 1048576;
      for (int j = 0; j < N; j++) {
          dividend /= divisor;
      }
      //asm volatile("ISB");
      asm volatile("msr DIT, #0");
    }

    printf("Div Final result: %lld\n", dividend);

    return 0;
}
