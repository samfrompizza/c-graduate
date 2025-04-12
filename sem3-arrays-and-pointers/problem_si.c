#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int moveright(int *arr, int key, int last) {
  for (int i = 0; i < last; i++) {
    if (arr[i] < key && arr[i + 1] >= key) {
      for (int j = last; j > i; j--)
        arr[j] = arr[j - 1];
      return i + 1;
    }
  }
  return last;
}

void inssort(int *arr, int len) {
  int i;
  for (i = 0; i < len; ++i) {
    int key, pos;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}

int main() {
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

  inssort(arr, num);

  for (int i = 0; i < num; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;

}
