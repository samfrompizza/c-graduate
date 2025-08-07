#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t
{
  struct node_t *next;
  int data;
};

struct node_t *read_list(FILE *inp)
{
  if (inp)
  {
    struct node_t *top_even = NULL;
    struct node_t *end_even = NULL;
    struct node_t *top_odd = NULL;
    struct node_t *end_odd = NULL;
    int buffer;

    while (fscanf(inp, "%d", &buffer) == 1)
    {
      if (buffer % 2 == 0)
      {
        struct node_t *new_node = calloc(1, sizeof(struct node_t));
        new_node->data = buffer;
        if (top_even == NULL) {
          top_even = new_node;
          end_even = new_node;
        } else {
          end_even->next = new_node;
          end_even = new_node;
        }
      } 
      if (buffer % 2 == 1) {
        struct node_t *new_node = calloc(1, sizeof(struct node_t));
        new_node->data = buffer;
        if (top_odd == NULL) {
          top_odd = new_node;
          end_odd = new_node;
        } else {
          end_odd->next = new_node;
          end_odd = new_node;
        }
      }
    }

    if (top_even) {
      end_even->next = top_odd;
      return top_even;
    } else {
      return top_odd;
    }
  }

  return NULL;
}

void delete_list(struct node_t *top)
{
  struct node_t *current;
  current = top;
  while (current != NULL)
  {
    struct node_t *next;
    next = current->next;
    free(current);
    current = next;
  }
}
