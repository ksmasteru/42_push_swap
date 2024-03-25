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
    printf("----%d-----\n", arr[i - 1]);
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

char ***fill_numbers(int ac, char **av, int *num_len)
{
  char ***numbers;
  int i;

  i = 0;
  numbers = (char ***)malloc(sizeof(char **) * (ac));
  if (numbers)
    return (NULL);
  while (i < ac - 1)
  {
    numbers[i] = ft_split(av[i + 1], ':');
    i++;
  }
  *num_len = 5;
  numbers[i] = NULL;
  return (numbers);
}