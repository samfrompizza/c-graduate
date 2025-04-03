#include <stdio.h>
#include <assert.h>

unsigned pow_mod(unsigned n, unsigned k, unsigned m) {
  unsigned mult = n % m;
  unsigned prod = 1;

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

// 67^^13 = 67 ^ (67^^4)^(67^^8) = 67 ^ ((67^^2)^(67^^2)) ^ ((67^^4)^(67^^4))
//x = 67^67
//y = x^x
//z = y^y
//67^^13 = 67^y^z

//2^^4 = 2 ^ (2^^3) = 2 ^ ()

unsigned rps(unsigned long long n, unsigned long long k, unsigned long long m) {
  unsigned mult = pow_mod(n, n, m);
  unsigned prod = 1;

  while (k > 1) {
    if ((k % 2) == 1) {
      prod = pow_mod(prod, mult, m);
      k -= 1;
    }
    mult = pow_mod(mult, mult, m);
    k /= 2;
  }
  return prod;
}

int main() {
  unsigned long long a, b, n;
  int s = scanf("%lld %lld %lld", &a, &b, &n);
  assert(s == 3);

  unsigned ans = rps(a, b, n);

  printf("%d\n", ans);

  return 0;
}