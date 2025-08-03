#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

unsigned partition(int *arr, unsigned low, unsigned high) {
  int pivot = arr[low];
  unsigned lptr = low + 1;
  unsigned rptr = high;

  while (lptr < rptr) {
    while ((arr[rptr] > pivot) && (lptr < rptr))
      rptr--;
    if (lptr < rptr) {
      arr[lptr] = arr[rptr];
      lptr++;
    }

    while ((arr[lptr] <= pivot) && (lptr < rptr))
      lptr++;
    if (lptr < rptr) {
      arr[rptr] = arr[lptr];
      rptr--;
    }
  }
  return lptr;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
  if (low >= high) return;
  unsigned pi = partition(arr, low, high);
  if (pi > low) qsort_impl(arr, low, pi - 1);
  qsort_impl(arr, pi + 1, high);
}

void qusort(int *arr, unsigned len) { 
  qsort_impl(arr, 0u, len - 1); 
}

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    abort();

  int *arr = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1)
      abort();
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  qusort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}