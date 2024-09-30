#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void vivod(unsigned long long x, 
           unsigned long long y) {

  unsigned long long p = 0, r = 0;

  if (y > x) {
    printf("0 ");
    p = x;
    x = y;
    y = p;
  }

  for (;y != 0;) {
    p = x / y;

    printf("%lld ", p);

    r = x % y;
    x = y;
    y = r;
  }

  printf("\n");

}

int main() {
  unsigned long long x = 0, y = 0;
  int res;

  res = scanf("%llu%llu", &x, &y);
  assert(res == 2);
  vivod(x, y);
  return 0;
}
