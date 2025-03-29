#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long extended_gcd(long long x, long long y, long long *a, long long *b) {
    if (y == 0) {
        *a = 1;
        *b = 0;
        return x;
    }

    long long a1, b1;
    long long gcd = extended_gcd(y, x % y, &a1, &b1);

    *a = b1;
    *b = a1 - (x / y) * b1;

    return gcd;
}

int main() {
  long long x = 0, y = 0, d;
  long long a = 0, b = 0;
  int res;

  res = scanf("%lld %lld", &x, &y);
  assert(res == 2);
  d = extended_gcd(x, y, &a, &b);
  if (d < 0) {
    long long t = d;
    d = -t;
    t = a;
    a = -t;
    t = b;
    b = -t;
  }
  printf("%lld %lld %lld\n", a, b, d);
  return 0;
}
