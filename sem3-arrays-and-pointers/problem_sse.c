#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int min_index(int const * parr, int len, int last) {
  int min_idx = last;
  for (int i = last; i < len; i++)
    if (parr[i] < parr[min_idx])
      min_idx = i;

  return min_idx;
}

void swap(int *v1, int *v2) {
  int tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}

int main() {
  int len, last;
  if (scanf("%d", &len) != 1)
    abort();

  int * arr = calloc(len, sizeof(int));
  for (int i = 0; i < len; i++)
    if (scanf("%d", &arr[i]) != 1)
      abort();

  if (scanf("%d", &last) != 1)
    abort();

  int pos = min_index(arr, len, last);
  swap(&arr[last], &arr[pos]);

  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");

  free(arr);
  return 0;
}
