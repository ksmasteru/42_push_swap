#include "push_swap.h"

int sa(t_stack **stack_a_head, int is_checker)
{
  t_stack *holder;
  t_stack *tmp;
  t_stack *tmp_next;

  if (*stack_a_head == NULL || (*stack_a_head)->next == NULL)
  {
    if (is_checker != 0)
      write(1, "sa\n", 3);
  }
  tmp = *stack_a_head;
  tmp_next = tmp->next->next;
  holder = tmp->next;
  holder->next = tmp;
  tmp->next = tmp_next;
  *stack_a_head = holder;
  if (is_checker != 0)
    write (1, "sa\n", 3);
  return (0);
}

int sb(t_stack **stack_b_head, int is_checker)
{

  t_stack *holder;
  t_stack *tmp;
  t_stack *tmp_next;

  if (*stack_b_head == NULL || (*stack_b_head)->next == NULL)
  {
    if (is_checker != 0)
      write(1, "sb\n", 3);
    return (0);
  }
  tmp = *stack_b_head;
  tmp_next = tmp->next->next;
  holder = tmp->next;
  holder->next = tmp;
  tmp->next = tmp_next;
  *stack_b_head = holder;
  if (is_checker != 0)
    write (1, "sb\n", 3);
  return (0);
}
int ss(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  sb(stack_b_head, 0);
  sa(stack_a_head, 0);
  if (is_checker != 0)
    write(1, "ss\n", 3);
  return (0);
}

int pa(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  /*didnt test if a is empty*/
  t_stack *b_next;
  t_stack *a_tmp;
  t_stack *b_tmp;

  if ((*stack_b_head) == NULL)
  {
    if (is_checker != 0)
      write(1, "pa\n", 3);
    return (0);
  }
  a_tmp = *stack_a_head;
  b_tmp = *stack_b_head;
  b_next = (*stack_b_head)->next;
  *stack_b_head = b_next;
  b_tmp->next = a_tmp;
  *stack_a_head = b_tmp;
  if (is_checker != 0)
    write(1, "pa\n", 3);
  return (0);
}

int pb(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  t_stack *a_next;
  t_stack *a_tmp;
  t_stack *b_tmp;

  if ((*stack_a_head) == NULL)
  {
    if (is_checker != 0)
      write(1, "pb\n", 3);
    return (0);
  }
  b_tmp = (*stack_b_head);
  a_tmp = (*stack_a_head);
  a_next = (*stack_a_head)->next;
  *stack_a_head = a_next;
  if (a_tmp != NULL)
    a_tmp->next =  b_tmp;
  *stack_b_head = a_tmp;
  if (is_checker != 0)
    write(1, "pb\n", 3);
  return (0);
}
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

int rrr(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  rra(stack_a_head, 0);
  rrb(stack_b_head, 0);
  if (is_checker != 0)
    write(1, "rrr\n", 4);
  return (0);
}
