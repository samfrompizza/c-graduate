#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int myrand()
{
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

int main()
{
  int num;
  if (scanf("%d", &num) != 1)
    abort();
  if (num == 0)
  {
    printf("0\n");
    return 0;
  }

  int *arr = calloc(num, sizeof(int));
  for (int i = 0; i < num; i++)
    scanf("%d", arr + i);

  for (int i = num - 1; i >= 0; i--)
  {
    int rand_id = myrand() % (i + 1);
    int tmp = arr[i];
    arr[i] = arr[rand_id];
    arr[rand_id] = tmp;
  }

  for (int i = 0; i < num; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}