#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

struct stacknode {
  struct stacknode *next;
  struct tree_t *data;
};

void push(struct stacknode **stack, struct tree_t *data) {
  struct stacknode *tmp = calloc(1, sizeof(struct stacknode));
  tmp->data = data;
  tmp->next = *stack;
  *stack = tmp;
}

struct tree_t * pop(struct stacknode **stack) {
  struct tree_t *data = (*stack)->data;
  struct stacknode *next = (*stack)->next;
  free(*stack);
  (*stack) = next;
  return data;
}

void print_pre(struct tree_t *top) {
  struct stacknode *s = NULL;
  push(&s, top);

  while (s != NULL)
  {
    struct tree_t *item = pop(&s);
    printf("%d ", item->data);
    if (item->right != NULL)
      push(&s, item->right);
    if (item->left)
      push(&s, item->left);
  }
  printf("\n");
}