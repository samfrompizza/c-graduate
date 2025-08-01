#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp) {
  int l = 0; 
  int r = num - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (cmp(key, (base + m * size)) == 0)
      return base + m * size;

    if (cmp(key, (base + m * size)) < 0)
      r = m - 1;

    if (cmp(key, (base + m * size)) > 0)
      l = m + 1;
  }

  return NULL;
}

