#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>

unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m) {
  unsigned long long mult = n % m;
  unsigned long long prod = 1;

  while (k > 0) {
    if ((k % 2) == 1) {
      prod = (prod * mult) % m;
      k -= 1;
    }
    mult = (mult * mult) % m;
    k /= 2;
  }
  return prod;
}

int main() {
  unsigned long long p;
  if (scanf("%lld", &p) != 1)
    abort();

  srand(time(NULL));
  uint8_t flag = 1;
  for (char i = 0; i < 100; i++) {
    unsigned long long a = rand();
    if (pow_mod(a, p - 1, p) != 1) {
      flag = 0;
      break;
    }
  }

  printf("%d\n", flag);

  return 0;
}