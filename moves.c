#include "push_swap.h"

int sa(t_stack **stack_a_head, int is_checker)
{

  t_stack *tmp;
  t_stack *tmp_next;

  if (*stack_a_head == NULL)
    return (-1);
  tmp = (*stack_a_head)->next;
  if (tmp == NULL)
    return (-1);
  tmp_next = tmp->next;
  tmp->next = *stack_a_head;
  (*stack_a_head)->next = tmp_next;
  *stack_a_head = tmp;
  if (is_checker != 0)
    write(1, "sa\n", 3);
  return (0);
}

int sb(t_stack **stack_b_head, int is_checker)
{

  t_stack *tmp;
  t_stack *tmp_next;

  if (*stack_b_head == NULL)
    return (-1);
  tmp = (*stack_b_head)->next;
  if (tmp == NULL)
    return (-1);
  tmp_next = tmp->next;
  tmp->next = *stack_b_head;
  (*stack_b_head)->next = tmp_next;
  *stack_b_head = tmp;
  if (is_checker != 0)
    write (1, "sb\n", 3);
  return (0);
}
int ss(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  if (sb(stack_b_head, 0) < 0)
    return (-1);
  if (sa(stack_a_head, 0) < 0)
    return (-1);
  if (is_checker != 0)
    write(1, "ss\n", 3);
  return (0);
}
int pa(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{

  t_stack *b_next;
  t_stack *b_tmp;
  t_stack *a_tmp;

  if ((*stack_b_head) == NULL)
    return (-1);
  b_next = (*stack_b_head)->next;
  b_tmp = (*stack_b_head);
  (*stack_b_head) = b_next;
  b_tmp->next = (*stack_a_head);
  (*stack_a_head) = b_tmp;
  if (is_checker != 0)
    write(1, "pa\n", 3);
  return (0);
}
int pb(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  t_stack *a_next;
  t_stack *a_tmp;

  if (*stack_a_head == NULL)
    return (-1);
  a_next = (*stack_a_head)->next;
  a_tmp = (*stack_a_head);
  (*stack_a_head) = a_next;
  a_tmp->next = (*stack_b_head);
  (*stack_b_head) = a_tmp;
  if (is_checker != 0)
    write(1, "pb\n", 3);
  return (0);
}
int ra(t_stack **stack_a_head, int is_checker)
{

  t_stack *tmp;
  t_stack *temp;
  
  if (*stack_a_head == NULL)
    return (-1);
  temp = (*stack_a_head)->next;
  tmp = *stack_a_head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  (*stack_a_head)->next = NULL;
  tmp->next = *stack_a_head;
  *stack_a_head = temp;
  if (is_checker != 0)
    write(1, "ra\n", 3);
  return (0);
}

int rb(t_stack **stack_b_head, int is_checker)
{
  t_stack *tmp;
  t_stack *temp;
  
  if (*stack_b_head == NULL)
    return (-1);
  temp = (*stack_b_head)->next;
  if (temp == NULL)
  {
    if (is_checker != 0)
      write(1, "rb\n", 3);
    return (0);
  }
  tmp = *stack_b_head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  (*stack_b_head)->next = NULL;
  tmp->next = *stack_b_head;
  *stack_b_head = temp;
  if (is_checker != 0)
    write(1, "rb\n", 3);
  return (0);
}

int rr(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  if (ra(stack_a_head, 0) < 0)
    return (-1);
  if (rb(stack_b_head, 0) < 0)
    return (-1);
  if (is_checker != 0)
    write(1,"rr\n", 3);
  return (0);
}


int rra(t_stack **stack_a_head, int is_checker)
{
  t_stack *tmp;
  t_stack *temp;
  t_stack *old_head;
  
  if (*stack_a_head == NULL)
    return (-1);
  tmp = *(stack_a_head);
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  temp = tmp->next;
  tmp->next = NULL;
  old_head = (*stack_a_head);
  *stack_a_head = temp;
  (*stack_a_head)->next = old_head;
  if (is_checker != 0)
    write(1, "rra\n", 4);
  return (0);
}

int rrb(t_stack **stack_b_head, int is_checker)
{
  t_stack *tmp;
  t_stack *temp;
  t_stack *old_head;
  
  if (*stack_b_head == NULL)
    return (-1);
  tmp = *(stack_b_head);
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  temp = tmp->next;
  tmp->next = NULL;
  old_head = (*stack_b_head);
  *stack_b_head = temp;
  (*stack_b_head)->next = old_head;
  if (is_checker != 0)
    write(1, "rrb\n", 4);
  return (0);
}

int rrr(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  if (rra(stack_a_head, 0) < 0)
    return (-1);
  if (rrb(stack_b_head, 0) < 0)
    return (-1);
  if (is_checker != 0)
    write(1, "rrr\n", 4);
  return (0);
}
