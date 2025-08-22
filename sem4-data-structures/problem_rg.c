#include <stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int (*generator_t)(int);

// определяет длину петли в генераторе
unsigned cycle_len(generator_t gen)
{
  int a = gen(0);
  int b = gen(a);
  int i = 1;

  while (a != b) {
    b = gen(b);
    ++i;
  }

  return i;
}