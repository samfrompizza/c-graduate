#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t
{
  struct node_t *next;
  int data;
};

// определяет есть ли петля в односвязном списке
// возвращает 0 если нет и 1 если есть
struct node_t *list_is_a_loop(struct node_t *top)
{
  if (top == NULL || top->next == NULL)
    return 0;

  struct node_t *turtle = top;
  struct node_t *rabbit = top->next;

  while (rabbit != NULL && rabbit->next != NULL)
  {
    if (turtle == rabbit)
      return turtle;
    turtle = turtle->next;
    rabbit = rabbit->next->next;
  }
  return 0;
}

// определяет длину петли в односвязном списке
// возвращает длину если есть, 0 если петли нет
int loop_len(struct node_t *top)
{
  struct node_t *loop_node = list_is_a_loop(top);
  if (loop_node == 0)
    return 0;

  struct node_t *rabbit = loop_node->next;
  int i = 1;

  while (rabbit != loop_node)
  {
    rabbit = rabbit->next;
    ++i;
  }

  return i;
}