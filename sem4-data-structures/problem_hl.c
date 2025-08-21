#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {
  struct node_t *next;
  int data;
};

// определяет есть ли петля в односвязном списке
// возвращает 0 если нет и 1 если есть
int list_is_a_loop(struct node_t *top)
{
    if (top == NULL || top->next == NULL)
        return 0;

    struct node_t *turtle = top;
    struct node_t *rabbit = top->next;

    while (rabbit != NULL && rabbit->next != NULL) {
        if (turtle == rabbit)
            return 1;
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    return 0;
}
