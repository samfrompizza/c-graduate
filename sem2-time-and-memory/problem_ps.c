#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct sieve_t {
  int n;
  char *s;
};

int sieve_bound(int num) {
  if (num > 20) {
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres);
  }
  return 72;
}

struct sieve_t init_sieve(int n) {
  struct sieve_t sv;
  sv.n = sieve_bound(n);
  sv.s = calloc(sv.n, sizeof(char));
  return sv;
}

void free_sieve(struct sieve_t *sv) {
  free(sv->s);
  sv->n = 0;
  sv->s = 0;
}

int is_prime(struct sieve_t sv, int n) {
  assert(n < sv.n);
  return (sv.s[n] == 1) ? 0 : 1;
}

void fill_sieve(struct sieve_t *sv) {
  sv->s[0] = 1;
  sv->s[1] = 1;
  int i = 2;
  while (i <= (int) round(sqrt(sv->n))) {
    int j = i * i;
    while (j < sv->n) {
      sv->s[j] = 1;
      j += i;
    }
    do {
      i++;
    } while (!is_prime(*sv, i));
  }
}

int nth_prime(struct sieve_t *sv, int N) {
  int count = 0;
  for (int i = 0; i < sv->n; i++) {
    if (is_prime(*sv, i)) {
      count++;
      if (count == N) {
        return i;
      }
    }
  }
  return -1;
}

int main() {
  int N;
  int s = scanf("%d", &N);
  assert(s == 1);

  struct sieve_t sv = init_sieve(N);
  fill_sieve(&sv);
  printf("%d\n", nth_prime(&sv, N));

  return 0;
}