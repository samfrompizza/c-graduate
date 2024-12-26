#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long x, long long y) {
    assert(x != 0 && y != 0);
    if (x == 0)
        return y;
    if (y == 0)
        return x;

    while (y != 0) {
        long long q = x % y;  
        x = y;      
        y = q;     
    }
    return x;
} 

int main() {
  long long x = 0, y = 0, g;
  int res;

  res = scanf("%lld %lld", &x, &y);
  assert(res == 2);
  g = gcd(abs(x), abs(y));
  printf("%lld\n", g);
  return 0;
}
