#include "push_swap.h"

void print_stack(t_stack *head)
{
  t_stack *temp;
  
  temp = head;
  while (temp)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
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

t_stack *ft_lstadd_back(t_stack *old)
{
  t_stack *new;
  t_stack *temp;

  new = ft_lst_new(0);
  if (!new)
    return (NULL);
  old->next = new;
  return (new);
}

int *pop_stack(t_stack **head)
{
  t_stack *tmp;

  tmp = (*head)->next;
  *head =  tmp;
  return (0);
}
int push_value(int a, t_stack **head)
{
  t_stack *new;
  t_stack *tmp;

  new = ft_lst_new(a);
  if (!new)
    exit(1);
  tmp = *head;
  *head = new;
  new->next = tmp;
  return (0);
}