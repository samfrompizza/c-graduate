#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

void print_pre(struct tree_t *top) {
  printf("%d ", top->data);
  if (top->left != NULL)
    print_pre(top->left);
  if (top->right != NULL)
    print_pre(top->right);
}