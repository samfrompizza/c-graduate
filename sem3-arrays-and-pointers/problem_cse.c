#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*cmp_t)(void const * lhs, void const * rhs);

void swap(void * parr, int a, int b, int eltsize) {
  char *arr = parr;
  char *elemA = arr + a * eltsize;
  char *elemB = arr + b * eltsize;
  char *temp = malloc(eltsize);

  memcpy(temp, elemA, eltsize);
  memcpy(elemA, elemB, eltsize);
  memcpy(elemB, temp, eltsize);

  free(temp);
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
  int min_id = nsorted;
  for (int i = nsorted + 1; i < numelts; i++)
    if (cmp(parr + i * eltsize, parr + min_id * eltsize) == 1)
      min_id = i;

  swap(parr, nsorted, min_id, eltsize);

  return 0;
}