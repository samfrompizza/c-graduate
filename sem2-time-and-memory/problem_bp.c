#include <stdio.h>
#include <assert.h>

int main() {
  int x;
  int s = scanf("%d", &x);
  assert(s == 1);

  if (x == 0) {
    printf("NO\n");
    return 0;
  }

  int xmin = 0;
  for (int i = 0; i < 32; i++) {
    int val = (x >> i) & 1u;
    if (val == 1) {
      xmin = i;
      break;
    }
  }

  int xmax = 0;
  for (int i = 31; i > 0; i--) {
    int val = (x >> i) & 1u;
    if (val == 1) {
      xmax = i;
      break;
    }
  }

  printf("%d %d\n", xmax, xmin);

  return 0;
}
