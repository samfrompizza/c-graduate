#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ull;

ull get_pisano_period(ull m) {
  ull first = 0ull, second = 1ull;
  for(ull i = 0; i < m * m; i++) {
    ull tmp = second;
    second = ((second % m) + (first % m)) % m;
    first = tmp;
    if (first == 0 && second == 1)
      return i + 1;
  }
  return m * m;
}

ull fib_mod(ull x, ull m, ull pisano) {
  ull first = 0ull, second = 1ull;
  x %= pisano;
  if (x == 0 || x == 1)
    return x;
  for (ull idx = 2; idx <= x; idx++) {
    ull tmp = second;
    second = ((second % m) + (first % m)) % m;
    first = tmp;
  }
  return second;
}

int main() {
  ull x, m;
  int s = scanf("%lld %lld", &x, &m);
  assert(s == 2);

  ull pp = get_pisano_period(m);
  printf("%lld %lld\n", fib_mod(x, m, pp), pp);

  return 0;
}