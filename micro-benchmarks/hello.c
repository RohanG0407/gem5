#include <stdio.h>

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

    printf("Final result: %lld\n", result);
    return 0;
}
