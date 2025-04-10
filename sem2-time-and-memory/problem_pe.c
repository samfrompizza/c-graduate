#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct sieve_t
{
  unsigned int n;
  unsigned char *s;
};

unsigned int sieve_bound(int num)
{
  if (num > 20)
  {
    double dnum = num;
    double dres = (dnum * (log(dnum) + log(log(dnum))));
    return (int)round(dres);
  }
  return 72;
}

struct sieve_t init_sieve(int n)
{
  struct sieve_t sv;
  sv.n = sieve_bound(n);
  sv.s = calloc(sv.n, sizeof(char));
  return sv;
}

void free_sieve(struct sieve_t *sv)
{
  free(sv->s);
  sv->n = 0;
  sv->s = 0;
}

unsigned int is_prime(struct sieve_t *sv, unsigned n)
{
  return (((sv->s[n / 8] >> (n % 8)) & 1u) == 1) ? 0 : 1;
}

void fill_sieve(struct sieve_t *sv)
{
  sv->s[0] |= (1u << 0);
  sv->s[0] |= (1u << 1);
  unsigned long long i = 2;
  while (i < sv->n * 8)
  {
    if (!is_prime(sv, i)) {
      i++;
      continue;
    }
    unsigned long long j = i * i;
    while (j < sv->n * 8)
    {
      sv->s[j / 8] |= (1u << (j % 8));
      j += i;
    }
    i++;
  }
}

unsigned int nth_prime(struct sieve_t *sv, unsigned int N)
{
  unsigned int count = 0;
  for (unsigned int i = 0; i < sv->n * 8; i++)
  {
    if (is_prime(sv, i))
    {
      count++;
      if (count == N)
      {
        return i;
      }
    }
  }
  return 0;
}

int main()
{
  unsigned int N;
  int s = scanf("%u", &N);
  assert(s == 1);

  struct sieve_t sv = init_sieve(N);
  fill_sieve(&sv);
  printf("%u\n", nth_prime(&sv, N));

  free_sieve(&sv);
  return 0;
}