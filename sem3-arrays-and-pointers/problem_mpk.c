#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
  unsigned long long n;
  unsigned long long *p;
} Poly;

Poly mult(Poly lhs, Poly rhs)
{
  Poly ret = {rhs.n + lhs.n - 1, NULL};
  ret.p = calloc(ret.n, sizeof(unsigned long long));

  if (ret.n == 1) {
    ret.p[0] = lhs.p[0] * rhs.p[0];
    return ret;
  } else {
    Poly lhs1 = {lhs.n / 2, lhs.p + ((lhs.n /2) * sizeof(unsigned long long))};
    Poly lhs0 = {lhs.n / 2, lhs.p};
    Poly lhs10 = {lhs.n / 2, NULL};
    lhs10.p = calloc(lhs10.n, sizeof(unsigned long long));
    for (unsigned long long i = 0; i < lhs10.n; ++i)
      lhs10.p[i] = lhs0.p[i] + lhs1.p[i];

    Poly rhs1 = {rhs.n / 2, rhs.p + ((rhs.n /2) * sizeof(unsigned long long))};
    Poly rhs0 = {rhs.n / 2, rhs.p};
    Poly rhs10 = {rhs.n / 2, NULL};
    rhs10.p = calloc(rhs10.n, sizeof(unsigned long long));
    for (unsigned long long i = 0; i < rhs10.n; ++i)
      rhs10.p[i] = rhs0.p[i] + rhs1.p[i];

    Poly first = mult(lhs1, rhs1);
    Poly second = mult(lhs10, rhs10);
    Poly third = mult(lhs0, rhs0);

    for (unsigned long long i = 0; i < first.n; ++i)
      ret.p[ret.n - first.n + i] += first.p[i];

    for (unsigned long long i = 0; i < second.n; ++i)
      ret.p[ret.n / 2 - second.n + i] += (second.p[i] - first.p[i] - third.p[i]);

    for (unsigned long long i = 0; i < third.n; ++i)
      ret.p[i] += third.p[i];

    free(lhs10.p);
    free(rhs10.p);
    free(first.p);
    free(second.p);
    free(third.p);

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
}

void poly_print(Poly ret)
{
  for (unsigned long long i = 0; i < ret.n; ++i)
  {
    printf("%lld ", ret.p[i]);
  }
  printf("\n");
}

int main()
{
  Poly lhs, rhs;
  if (scanf("%lld %lld", &lhs.n, &rhs.n) != 2)
    abort();
  lhs.p = calloc(lhs.n, sizeof(unsigned long long));
  rhs.p = calloc(rhs.n, sizeof(unsigned long long));
  for (unsigned long long i = 0; i < lhs.n; ++i)
  {
    if (scanf("%lld", &lhs.p[i]) != 1)
      abort();
  }
  for (unsigned long long i = 0; i < rhs.n; ++i)
  {
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