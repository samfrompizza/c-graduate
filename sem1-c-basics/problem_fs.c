#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define MAX_FACT_ARG 15

unsigned long long factorial(int n) {
  static unsigned long long facts[MAX_FACT_ARG] = {};
  if (facts[n] != 0)
    return facts[n];
  if (n == 0 || n == 1)
    return 1;
  facts[n] = n * factorial(n - 1);
  return facts[n];
}

int main() {
  unsigned long long x;
  int s = scanf("%lld", &x);
  assert(s == 1);

  int repr[MAX_FACT_ARG] = {};

  int max_i = 0;
  for (int i = 1; i <= MAX_FACT_ARG; i++) {
    if (factorial(i) > x) {
      max_i = i - 1;
      break;
    }
  }

  for (int i = max_i; i >= 1; i--) {
    repr[i] = x / factorial(i);
    x -= repr[i] * factorial(i);
    printf("%d.", repr[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}