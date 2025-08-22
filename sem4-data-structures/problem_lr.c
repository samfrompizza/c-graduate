#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
  struct node_t *next;
  int data;
};

struct node_t * reverse(struct node_t *top)
{
  struct node_t *fst, *snd;
  if (top == NULL) return NULL;
  if (top->next == NULL) return top;
  fst = top;
  snd = top->next;
  top->next = NULL;

  while (snd != NULL) {
    struct node_t *tmp = snd->next;
    snd->next = fst;
    fst = snd;
    snd = tmp;
  }
  return fst;
}
