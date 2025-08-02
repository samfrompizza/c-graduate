#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void merge(int *arr, int l, int m, int r) {
  int i = 0; 
  int j = 0;
  int k = l;
  int n1 = m - l + 1;
  int n2 = r - m;
  int *L = malloc(n1*sizeof(int));
  int *R = malloc(n2*sizeof(int));

  for (int p = 0; p < n1; p++)
    L[p] = arr[l + p];
  for (int p = 0; p < n2; p++)
    R[p] = arr[m + 1 + p];

  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}