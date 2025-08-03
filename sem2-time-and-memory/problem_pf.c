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

uint8_t fermat_test(unsigned long long p) {
  srand(time(NULL));
  for (char i = 0; i < 100; i++) {
    unsigned long long a = rand();
    if (pow_mod(a, p - 1, p) != 1)
      return 0;
  }
  return 1;
}

void matrix_mult_mod(int * x, int * y, int * c) {
  unsigned long long m = 1u << 60;
  c[0] = (x[0] * y[0] % m + x[1] * y[2] % m) % m;
  c[1] = (x[0] * y[1] % m + x[1] * y[3] % m) % m;
  c[2] = (x[2] * y[0] % m + x[3] * y[2] % m) % m;
  c[3] = (x[2] * y[1] % m + x[3] * y[3] % m) % m;
}

void matrix_copy(int * src, int * dst) {
  for (int i = 0; i < 4; i++) {
    dst[i] = src[i];
  }
}

void matrix_pow_mod(int * x, int * res, int n) {
  unsigned long long prod[4] = {1, 0, 0, 1};
  unsigned long long tmp[4] = {1, 0, 0, 1};
  unsigned long long mult[4] = {};
  matrix_mult_mod(x, prod, mult);

  while (n > 0) {
    matrix_copy(prod, tmp);
    if ((n % 2) == 1) {
      matrix_mult_mod(tmp, mult, prod);
      n -= 1;
    }
    matrix_copy(mult, tmp);
    matrix_mult_mod(tmp, tmp, mult);
    n /= 2;
  }
  matrix_copy(prod, res);
}


unsigned long long fibop(int i) {

}

int main() {
  int k, n;
  if (scanf("%d%d", &k, &n) != 2)
    abort();

  return 0;
}
