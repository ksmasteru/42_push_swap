#include "../includes/push_swap.h"

int ra(t_stack **stack_a_head, int is_checker)
{
  t_stack *a_tmp;
  t_stack *a_next;
  t_stack *tail;
  
  if (*stack_a_head == NULL)
  {
    if (is_checker != 0)
      write (1, "ra\n", 3);
    return (0);
  }
  a_tmp = (*stack_a_head);
  a_next = (*stack_a_head)->next;
  if (a_next == NULL)
  {
    if (is_checker != 0)
      write (1, "ra\n", 3);
    return (0);
  }
  tail = get_tail(*stack_a_head);
  tail->next = a_tmp;
  a_tmp->next = NULL;
  *stack_a_head = a_next;
  if (is_checker != 0)
    write(1, "ra\n", 3);
  return (0);
}

int rb(t_stack **stack_b_head, int is_checker)
{
  t_stack *b_tmp;
  t_stack *b_next;
  t_stack *tail;
  
  if (*stack_b_head == NULL)
  {
    if (is_checker != 0)
      write (1, "rb\n", 3);
    return (0);
  }
  b_tmp = (*stack_b_head);
  b_next = (*stack_b_head)->next;
  if (b_next == NULL)
  {
    if (is_checker != 0)
      write (1, "rb\n", 3);
    return (0);
  }
  tail = get_tail(*stack_b_head);
  tail->next = b_tmp;
  b_tmp->next = NULL;
  *stack_b_head = b_next;
  if (is_checker != 0)
    write(1, "rb\n", 3);
  return (0);
}

int rr(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  ra(stack_a_head, 0);
  rb(stack_b_head, 0);
  if (is_checker != 0)
    write(1,"rr\n", 3);
  return (0);
}


int rra(t_stack **stack_a_head, int is_checker)
{
  t_stack *tail;
  t_stack *prev_tail;
  
  if (*stack_a_head == NULL)
  {
    if (is_checker != 0)
      write (1, "rra\n", 4);
    return (0);
  }
  if ((*stack_a_head)->next == NULL)
  {
   if (is_checker != 0)
      write (1, "rra\n", 4);
    return (0);
  }
  tail = *stack_a_head;
  while (tail->next != NULL)
  {
    prev_tail = tail;
    tail = tail->next;
  }
  prev_tail->next = NULL;
  tail->next = *stack_a_head;
  *stack_a_head = tail;
  if (is_checker != 0)
    write(1, "rra\n", 4);
  return (0);
}

int rrb(t_stack **stack_b_head, int is_checker)
{
  t_stack *tail;
  t_stack *prev_tail;
  
  if (*stack_b_head == NULL)
  {
    if (is_checker != 0)
      write (1, "rrb\n", 4);
    return (0);
  }
  if ((*stack_b_head)->next == NULL)
  {
   if (is_checker != 0)
      write (1, "rrb\n", 4);
    return (0);
  }
  tail = *stack_b_head;
  while (tail->next != NULL)
  {
    prev_tail = tail;
    tail = tail->next;
  }
  prev_tail->next = NULL;
  tail->next = *stack_b_head;
  *stack_b_head = tail;
  if (is_checker != 0)
    write(1, "rrb\n", 4);
  return (0);
}
