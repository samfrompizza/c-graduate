#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

int check_is_bst_par(struct tree_t *top, int l_border, int r_border) {
  if ((top-> data <= l_border) || (top->data >= r_border))
    return 0;

  if (top->left)
    if (!check_is_bst_par(top->left, l_border, top->data))
      return 0;
  if (top->right)
    if (!check_is_bst_par(top->right, top->data, r_border))
      return 0;

  return 1;
}

int check_is_bst(struct tree_t *top) {
  return check_is_bst_par(top, INT_MIN, INT_MAX);
}