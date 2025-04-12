#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
  int num;
  if (scanf("%d", &num) != 1)
    abort();
  if (num == 0)
  {
    printf("0 0\n");
    return 0;
  }

  int tmp;
  int max = -2147483648;
  int min = 2147483647;
  for (int i = 0; i < num; i++)
  {
    scanf("%d", &tmp);
    if (tmp > max)
      max = tmp;
    if (tmp < min)
      min = tmp;
  }

  printf("%d %d\n", min, max);

  return 0;
}