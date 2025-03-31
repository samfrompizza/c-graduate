#include <stdio.h>
#include <assert.h>

int main() {
  int a, b, n;
  int s = scanf("%d %d %d", &a, &b, &n);
  assert(s == 3);

  int ans = a;
  for (int i = 1; i < b; i++) {
    ans *= a;
    ans %= n;
  }
  printf("%d\n", ans % n);

  return 0;
}