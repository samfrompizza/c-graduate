#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long fib_mod(unsigned long long x, unsigned long long m) {
  unsigned long long first = 0ull, second = 1ull;
  if (x == 0 || x == 1)
    return x;
  for (unsigned long long idx = 2; idx <= x; idx++) {
    unsigned long long tmp = second;
    second = ((second % m) + (first % m)) % m;
    first = tmp;
  }
  return second;
}

int main() {
  unsigned long long x, m;
  int s = scanf("%lld %lld", &x, &m);
  assert(s == 2);

  printf("%lld\n", fib_mod(x, m));

  return 0;
}