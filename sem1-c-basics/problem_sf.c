#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ull;

static ull fib[94] = {1, 1};

int main() {
  ull x;
  int repr[94] = {};
  int s = scanf("%lld", &x);
  assert(s == 1);

  for (int i = 2; i < 94; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    // printf("%lld\n", fib[i]);
  }

  int imx = 0;
  for (int i = 93; i >= 1; i--) {
    if (fib[i] <= x) {
      if (i >= imx)
        imx = i;
      repr[i] = 1;
      x -= fib[i];
    }
  }

  for (int i = imx; i > 0; i--) {
    printf("%d", repr[i]);
  }
  printf("\n");

  return 0;
}