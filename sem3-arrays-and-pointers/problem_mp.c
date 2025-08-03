#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
  unsigned long long n;
  unsigned long long *p;
} Poly;

Poly mult(Poly lhs, Poly rhs) {
  Poly ret = {rhs.n + lhs.n - 1, NULL};
  ret.p = calloc(ret.n, sizeof(unsigned long long));

  for (unsigned long long i = 0; i < lhs.n; ++i) {
    for (unsigned long long j = 0; j < rhs.n; ++j) {
      ret.p[i + j] += lhs.p[i] * rhs.p[j];
    }
  }

  unsigned long long n = ret.n;

  for (unsigned long long i = 0; i < n; ++i) {
    if (ret.p[n - 1 - i] == 0) {
      ret.n -= 1;
    } else {
      return ret;;
    }
  }

  return ret;
}

void poly_print(Poly ret) {
  for (unsigned long long i = 0; i < ret.n; ++i) {
    printf("%lld ", ret.p[i]);
  }
  printf("\n");
}

int main() {
  Poly lhs, rhs;
  if (scanf("%lld %lld", &lhs.n, &rhs.n) != 2)
    abort();
  lhs.p = calloc(lhs.n, sizeof(unsigned long long));
  rhs.p = calloc(rhs.n, sizeof(unsigned long long));
  for (unsigned long long i = 0; i < lhs.n; ++i) {
    if (scanf("%lld", &lhs.p[i]) != 1)
      abort();
  }
  for (unsigned long long i = 0; i < rhs.n; ++i) {
    if (scanf("%lld", &rhs.p[i]) != 1)
      abort();
  }

  Poly res = mult(lhs, rhs);
  poly_print(res);

  free(rhs.p);
  free(lhs.p);
  free(res.p);

  return 0;
}
