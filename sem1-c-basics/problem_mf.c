#include <stdio.h>
#include <assert.h>

void matrix_mult_mod(int * x, int * y, int * c, int m) {
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

void matrix_pow_mod(int * x, int * res, int n, int m) {
  int prod[4] = {1, 0, 0, 1};
  int tmp[4] = {1, 0, 0, 1};
  int mult[4] = {};
  matrix_mult_mod(x, prod, mult, m);

  while (n > 0) {
    matrix_copy(prod, tmp);
    if ((n % 2) == 1) {
      matrix_mult_mod(tmp, mult, prod, m);
      n -= 1;
    }
    matrix_copy(mult, tmp);
    matrix_mult_mod(tmp, tmp, mult, m);
    n /= 2;
  }
  matrix_copy(prod, res);
}

int main() {
  int x00, x01, x10, x11, n, m;
  int s = scanf("%d%d%d%d%d%d", &x00, &x01, &x10, &x11, &n, &m);
  assert(s == 6);

  int x[4] = {x00, x01, x10, x11};
  int res[4] = {};
  matrix_pow_mod(x, res, n, m);
  printf("%d %d %d %d\n", res[0], res[1], res[2], res[3]);

  return 0;
}