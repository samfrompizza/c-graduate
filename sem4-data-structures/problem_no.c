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

void tree_del(struct tree_t *top) {
    if (top == NULL) return;
    tree_del(top->left);
    tree_del(top->right);
    free(top);
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  if (fp) {
    int n;
    fscanf(fp, "%d", &n);
    int * arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i)
      fscanf(fp, "%d", &arr[i]);

    struct tree_t *top = calloc(1, sizeof(struct tree_t));
    struct tree_t *fst = top;
    struct tree_t *sec = top;
    top->data = arr[0];
    for (int i = 1; i < n; ++i) {
      while (fst) {
        sec = fst;
        if (arr[i] > sec->data)
          fst = sec->right;
        else 
          fst = sec->left;
      }
      if (arr[i] > sec->data) {
        sec->right = calloc(1, sizeof(struct tree_t));
        sec->right->data = arr[i];
        } else {
        sec->left = calloc(1, sizeof(struct tree_t));
        sec->left->data = arr[i];
        }
      fst = top;
      sec = top;
    }

    print_pre(top);
    printf("\n");

    tree_del(top);
    free(arr);
  }
}
