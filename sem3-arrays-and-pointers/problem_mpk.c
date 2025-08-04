#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Max power, when naive method is used
#define BASE_THRESHOLD 64

typedef struct
{
  unsigned long long n;
  unsigned long long *p;
} Poly;

Poly mult(Poly lhs, Poly rhs)
{
  Poly ret = {rhs.n + lhs.n - 1, NULL};
  ret.p = calloc(ret.n, sizeof(unsigned long long));

  // Naive algorythm in BASE case
  if (ret.n <= BASE_THRESHOLD)
  {
    for (unsigned long long i = 0; i < lhs.n; ++i)
    {
      for (unsigned long long j = 0; j < rhs.n; ++j)
      {
        ret.p[i + j] += lhs.p[i] * rhs.p[j];
      }
    }
    return ret;
  }

  // Karacuba algorythm
  unsigned long long half = lhs.n / 2;
  assert(lhs.n == rhs.n);

  Poly lhs1 = {half, lhs.p + (half)};
  Poly lhs0 = {half, lhs.p};
  Poly lhs10 = {half, calloc(lhs10.n, sizeof(unsigned long long))};
  Poly rhs1 = {half, rhs.p + (half)};
  Poly rhs0 = {half, rhs.p};
  Poly rhs10 = {half, calloc(rhs10.n, sizeof(unsigned long long))};
  // (lhs10.n == rhs10.n) because of (lhs.n == rhs.n)
  for (unsigned long long i = 0; i < lhs10.n; ++i)
  {
    lhs10.p[i] = lhs0.p[i] + lhs1.p[i];
    rhs10.p[i] = rhs0.p[i] + rhs1.p[i];
  }

  // Recursive calculating of A1B1, ((A0+A1)(B0+B1)), A0B0 
  Poly first = mult(lhs1, rhs1);
  Poly second = mult(lhs10, rhs10);
  Poly third = mult(lhs0, rhs0);

  // AB = A1B1*x^n + ((A0+A1)(B0+B1)-A1B1-A0B0)*x^half + A0B0
  for (unsigned long long i = 0; i < third.n; i++)
    ret.p[i] += third.p[i];

  for (unsigned long long i = 0; i < second.n; i++)
    ret.p[i + half] += second.p[i] - first.p[i] - third.p[i];

  for (unsigned long long i = 0; i < first.n; i++)
    ret.p[i + 2 * half] += first.p[i];

  free(lhs10.p);
  free(rhs10.p);
  free(first.p);
  free(second.p);
  free(third.p);

  return ret;
}

void poly_print(Poly ret)
{
  unsigned long long last = 0;
  for (unsigned long long i = ret.n - 1; i > 0; --i)
  {
    if (ret.p[i] != 0)
    {
      last = i;
      break;
    }
  }
  for (unsigned long long i = 0; i < last; ++i)
  {
    printf("%llu ", ret.p[i]);
  }
  printf("%llu", ret.p[last]);
  printf("\n");
}

int main()
{
  Poly lhs, rhs;
  if (scanf("%llu %llu", &lhs.n, &rhs.n) != 2)
    abort();
  lhs.p = calloc(lhs.n, sizeof(unsigned long long));
  rhs.p = calloc(rhs.n, sizeof(unsigned long long));
  for (unsigned long long i = 0; i < lhs.n; ++i)
  {
    if (scanf("%llu", &lhs.p[i]) != 1)
      abort();
  }
  for (unsigned long long i = 0; i < rhs.n; ++i)
  {
    if (scanf("%llu", &rhs.p[i]) != 1)
      abort();
  }

  Poly res = mult(lhs, rhs);
  poly_print(res);

  free(rhs.p);
  free(lhs.p);
  free(res.p);

  return 0;
}