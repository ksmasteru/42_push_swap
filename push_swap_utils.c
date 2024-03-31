#include "push_swap.h"

int *stack_to_array(t_stack *a_head, int size)
{
  int i;
  int *arr;
  i = 0;
  arr = (int *)malloc(sizeof(int) * size);
  if (!arr)
    return (NULL);
  while (i < size)
  {
    arr[i++] = a_head->data;
    a_head = a_head->next;
  }
  return (arr);
}

t_stack *ft_lst_new(int data)
{
  t_stack *new;

  new = malloc(sizeof(t_stack));
  if (!new)
    return (NULL);
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_stack *ft_lstadd_back(t_stack *old, int data)
{
  t_stack *new;
  t_stack *temp;

  new = ft_lst_new(data);
  if (!new)
    return (NULL);
  old->next = new;
  return (new);
}

int stack_len(t_stack *head)
{
  int i;
  t_stack *tmp;

  i = 0;
  tmp = head;
  while (tmp != NULL)
  {
    tmp = tmp->next;
    i++;
  }
  return (i);
}
