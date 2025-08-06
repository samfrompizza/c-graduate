#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOTATION 10

int power(int base, int m)
{
  int pow = 1;
  for (int i = 0; i < m; ++i)
    pow *= base;

  return pow;
}

void radix_step(int n, int m, int *arr)
{
  int *count = calloc(NOTATION, sizeof(int));
  int *prefix = calloc(NOTATION, sizeof(int));
  int *output = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++) {
    int d = (arr[i] / power(NOTATION, m)) % NOTATION;
    count[d]++;
  }

  prefix[0] = count[0];
  for (int i = 1; i < NOTATION; i++) {
    prefix[i] = prefix[i-1] + count[i];
  }

  for (int i = n-1; i >= 0; i--) {
    int d = (arr[i] / power(NOTATION, m)) % NOTATION;
    output[prefix[d] - 1] = arr[i];
    prefix[d]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  free(count);
  free(prefix);
  free(output);
}

int main()
{
  int n, m;
  if (scanf("%d", &n) != 1)
    abort();
  int *arr = calloc(n, sizeof(int));
  for (int i = 0; i < n; ++i)
  {
    if (scanf("%d", &arr[i]) != 1)
      abort();
  }
  if (scanf("%d", &m) != 1)
    abort();

  radix_step(n, m, arr);

  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");

  free(arr);

  return 0;
}
