#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int triple_gcd(int a, int b, int c) {
  int d = gcd(a, b);
  int f = gcd(c, d);
  return f;
} 

int check_for_solution(int ab_gcd, int c){
  if (c % ab_gcd == 0)
    return 1;
  else
    return 0;
}

int main() {
  // ax + by = c
  int x = 1, y = 0;
  int a = 0, b = 0, c = 0;

  int res = scanf("%d %d %d", &a, &b, &c);
  assert(res == 3);
  int ab_gcd = gcd(a, b);
  
  if (check_for_solution(ab_gcd, c) == 0){
    printf("NONE\n");
    return 0;
  }
  
  while ((c - x * a) % b != 0)
    x++;
  
  y = (c - x * a) / b;
  printf("%d %d\n", x, y);

  return 0;
}
