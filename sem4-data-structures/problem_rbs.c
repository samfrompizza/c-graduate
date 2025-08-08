#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t
{
  struct node_t *next;
  int data;
};

int main()
{
  int n;
  int max = 0;
  int buck_size;
  if (scanf("%d", &n) != 1)
    abort();
  int *arr = calloc(n, sizeof(int));
  struct node_t **buckets_top = calloc(n, sizeof(struct node_t *));
  struct node_t **buckets_tail = calloc(n, sizeof(struct node_t *));
  for (int i = 0; i < n; ++i)
  {
    if (scanf("%d", &arr[i]) != 1)
      abort();
    if (arr[i] > max)
      max = arr[i];
  }

  buck_size = (max / n);
  for (int i = 0; i < n; ++i)
  {
    int idx = arr[i] / buck_size;
    if (idx >= n)
      idx = n - 1;
    struct node_t *new_node = calloc(1, sizeof(struct node_t));
    new_node->data = arr[i];
    if (buckets_top[idx] == NULL)
    {
      buckets_top[idx] = new_node;
      buckets_tail[idx] = new_node;
    }
    else
    {
      buckets_tail[idx]->next = new_node;
      buckets_tail[idx] = new_node;
    }
  }

  for (int i = 0; i < n; i++)
  {
    struct node_t *sorted = NULL;
    struct node_t *cur = buckets_top[i];
    while (cur)
    {
      struct node_t *next = cur->next;
      if (!sorted || cur->data < sorted->data)
      {
        cur->next = sorted;
        sorted = cur;
      }
      else
      {
        struct node_t *p = sorted;
        while (p->next && p->next->data < cur->data)
          p = p->next;
        cur->next = p->next;
        p->next = cur;
      }
      cur = next;
    }
    buckets_top[i] = sorted;
  }

  for (int i = 0; i < n; ++i)
  {
    struct node_t *current;
    current = buckets_top[i];
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("0 ");
  }
  printf("\n");

  for (int i = 0; i < n; ++i)
  {
    struct node_t *current;
    current = buckets_top[i];
    while (current != NULL)
    {
      struct node_t *next;
      next = current->next;
      free(current);
      current = next;
    }
  }

  free(arr);
  free(buckets_top);
  free(buckets_tail);

  return 0;
}
