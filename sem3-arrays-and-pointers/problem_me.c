#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int majority_element(const int *parr, int len)
{
  int i = 0;
  int count = 0;
  int m = parr[0];

  for (int j = 1; j < len; ++j)
  {
    if (m == parr[j])
      ++i;
    if ((m != parr[j]) && (i == 0))
      m = parr[j];
    if ((m != parr[j]) && (i > 0))
      --i;
  }

  for (int j = 0; j < len; ++j) {
    if (m == parr[j])
      ++count;
  }
  if (count > (len / 2))
    return m;

  return -1;
}
