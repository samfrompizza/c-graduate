#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_prime(unsigned x) {
  if (x < 2)
    return 0;
    
  for (int j = 2; j * j <= x; j++) {
    if ((x % j) == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, m;
  int s = scanf("%d", &n);
  assert(s == 1);

  for (int i = 1; n > 0; i++) {
    if (is_prime(i)) {
      m = i;
      n--;
    }
  }
  printf("%d\n", m);

  return 0;
}