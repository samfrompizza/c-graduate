#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct point_t {
  int x, y;
};
struct triangle_t {
  struct point_t pts[3];
};

int double_area(struct triangle_t tr) {
  int first_term = tr.pts[0].x * (tr.pts[1].y - tr.pts[2].y);
  int second_term = tr.pts[0].y * (tr.pts[1].x - tr.pts[2].x);
  int third_term = tr.pts[1].x * tr.pts[2].y - tr.pts[2].x * tr.pts[1].y;
  return abs(first_term - second_term + third_term);
}

int main() {
  struct triangle_t t;
  int s = scanf("%d%d%d%d%d%d", &t.pts[0].x, &t.pts[0].y,
                                &t.pts[1].x, &t.pts[1].y,
                                &t.pts[2].x, &t.pts[2].y);
  assert(s == 6);

  printf("%d\n", double_area(t));

  return 0;
}