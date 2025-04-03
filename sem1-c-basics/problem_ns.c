#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define MAX_STR_SIZE (sizeof(unsigned int) * CHAR_BIT)

void solve(uint32_t x, uint32_t y, char * ans, size_t i) {
  ans[i] = (x % y )+ '0';
  if(x / y == 0) return;
  solve(x / y, y, ans, i + 1);
}

char * strrev(char * str){ 
  int length = strlen(str);
  for(int i = 0; i < length / 2; i++){
    char t = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = t;
  }

  return str;
}

int main() {
  uint32_t x, y;
  int s = scanf("%u %u", &x, &y);
  assert(s == 2);

  char ans[MAX_STR_SIZE] = {};
  solve(x, y, ans, 0);

  printf("%s\n", strrev(ans));

  return 0;
}
