#include <stdio.h>
#include <assert.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  unsigned long long q;
  if (b > a)
    return gcd(b, a);
  q = a % b;
  if (q == 0)
    return b;
  return gcd(b, q);
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}

int main() {
  int n;
  int s = scanf("%d", &n); 
  assert(s == 1);

  unsigned long long tmp = 2;
  for (int i = 2; i <= n; i++)
    tmp = lcm(tmp, i);
  printf("%lld\n", tmp);

  return 0;
}
