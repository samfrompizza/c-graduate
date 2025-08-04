#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    abort();
  int *arr = calloc(n, sizeof(int));
  int max = 0;
  for (int i = 0; i < n; ++i) {
    if (scanf("%d", &arr[i]) != 1)
      abort();
    if (arr[i] > max)
      max = arr[i];
  }

  int *buck = calloc(max + 1, sizeof(int));
  for (int i = 0; i < n; ++i)
    buck[arr[i]] += 1;

  for (int i = 0; i <= max; ++i)
    printf("%d ", buck[i]);
  printf("\n");

  return 0;
}
