#include <m5_mmap.h>
#include <stdio.h>

#include <gem5/m5ops.h>

#define N 20

int main(int argc, char *argv[]) {
    long long result = 1;
    long long factor = 2;

    for (int i = 0; i < N * 100; i++) {
      result = 1;
      for (int j = 0; j < N; j++) {
          result *= factor;
      }
    }

    printf("Mult Final result: %lld\n", result);

    long long dividend = 1048576;
    long long divisor = 1;

    for (int i = 0; i < N * 100; i++) {
      dividend = 1048576;
      for (int j = 0; j < N; j++) {
          dividend /= divisor;
      }
    }

    printf("Div Final result: %lld\n", dividend);

    return 0;
}
