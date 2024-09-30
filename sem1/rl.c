#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    if (x == 0)
        return y;
    if (y == 0)
        return x;

    while (y != 0) {
        unsigned long long q = x % y;  
        x = y;      
        y = q;     
    }
    return x;
} 

int main() {
  unsigned long long x = 0, y = 0, g;
  int res;

  res = scanf("%llu %llu", &x, &y);
  assert(res == 2);
  g = gcd(x, y);
  printf("%llu\n", g);
  return 0;
}
