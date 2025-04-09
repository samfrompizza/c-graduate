#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

int main()
{
  int mnt, N;
  if (scanf("%d", &mnt) != 1)
    abort();

  uint8_t *x = calloc(mnt, sizeof(char));
  for (int i = 0; i < mnt; i++)
    if (scanf("%hhu", x + i) != 1)
      abort();

  if (scanf("%d", &N) != 1)
    abort();

  x[N / 8] ^= (1u << (N % 8));
  for (int i = 0; i < mnt; i++)
    printf("%hhu ", x[i]);
  printf("\n");

  free(x);
  return 0;
}