#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOTATION 10

int pow(int base, int m) {
  int pow = 1;
  for (int i = 0; i < m; ++i)
    pow *= base;

  return pow;
}

void radix_step(int n, int m, int *arr) {
  int *buff = calloc(NOTATION, sizeof(int));
  int *incl_scan = calloc(NOTATION, sizeof(int));
  for (int i = 0; i < n; ++i)
    buff[(arr[i] % pow(NOTATION, m)) / NOTATION] += 1; 

  for (int i = 0; i < n; ++i) {}

}

int main() {
  int n, m;
  if (scanf("%d", &n) != 1)
    abort();
  int *arr = calloc(n, sizeof(int));
  for (int i = 0; i < n; ++i) {
    if (scanf("%d", &arr[i]) != 1)
      abort();
  }
  if (scanf("%d", &m) != 1)
    abort();

  

  return 0;
}
