#include "push_swap.h"

void sa(t_stack **stack_a_head)
{
  // this is what hard feels like
  // swap the first 2 elemtns at the top of stack a
  t_stack *tmp;
  t_stack *tmp_next;

  tmp = (*stack_a_head)->next;
  if (tmp == NULL)
    return;
  tmp_next = tmp->next;
  tmp->next = *stack_a_head;
  (*stack_a_head)->next = tmp_next;
  *stack_a_head = tmp;
  write(1, "sa\n", 3);
}

void sb(t_stack **stack_b_head)
{
  // this is what hard feels like
  // swap the first 2 elemtns at the top of stack a
  t_stack *tmp;
  t_stack *tmp_next;

  tmp = (*stack_b_head)->next;
  if (tmp == NULL)
    return;
  tmp_next = tmp->next;
  tmp->next = *stack_b_head;
  (*stack_b_head)->next = tmp_next;
  *stack_b_head = tmp;
  write (1, "sb\n", 3);
}
void ss(t_stack **stack_a_head, t_stack **stack_b_head)
{
  sb(stack_b_head);
  sa(stack_a_head);
  write(1, "ss\n", 3);
}
void pa(t_stack **stack_a_head, t_stack **stack_b_head)
{
// Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
  t_stack *b_next;
  t_stack *b_tmp;
  t_stack *a_tmp;

  b_next = (*stack_b_head)->next;
  b_tmp = (*stack_b_head);
  (*stack_b_head) = b_next;
  b_tmp->next = (*stack_a_head);
  (*stack_a_head) = b_tmp;
  write(1, "pa\n", 3);
}
void pb(t_stack **stack_a_head, t_stack **stack_b_head)
{
//Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
  t_stack *a_next;
  t_stack *a_tmp;

  a_next = (*stack_a_head)->next;
  a_tmp = (*stack_a_head);
  (*stack_a_head) = a_next;

  a_tmp->next = (*stack_b_head);
  (*stack_b_head) = a_tmp;
  write(1, "pb\n", 3);
}
void ra(t_stack **stack_a_head)
{
 // Shift up all elements of stack a by 1.
//The first element becomes the last one.
  t_stack *tmp;
  t_stack *temp;
  
  temp = (*stack_a_head)->next;
  tmp = *stack_a_head;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  (*stack_a_head)->next = NULL;
  tmp->next = *stack_a_head;
  *stack_a_head = temp;
  write(1, "ra\n", 3);
}

void rb(t_stack **stack_b_head)
{
 // Shift up all elements of stack b by 1.
//The first element becomes the last one.
  t_stack *tmp;
  t_stack *temp;
  
  temp = (*stack_b_head)->next;
  tmp = *stack_b_head;
  while (tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  (*stack_b_head)->next = NULL;
  tmp->next = *stack_b_head;
  *stack_b_head = temp;
  write(1, "rb\n", 3);
}

void rr(t_stack **stack_a_head, t_stack **stack_b_head)
{
  ra(stack_a_head);
  rb(stack_b_head);
  write(1,"rr\n", 3);
}


void rra(t_stack **stack_a_head)
{
  // last element becomes first one.
  t_stack *tmp;
  t_stack *temp;
  t_stack *old_head;
  
  tmp = *(stack_a_head);
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  temp = tmp->next;
  tmp->next = NULL;
  old_head = (*stack_a_head);
  *stack_a_head = temp;
  (*stack_a_head)->next = old_head;
  write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b_head)
{
  // last element becomes first one.
  t_stack *tmp;
  t_stack *temp;
  t_stack *old_head;
  
  tmp = *(stack_b_head);
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  temp = tmp->next;
  tmp->next = NULL;
  old_head = (*stack_b_head);
  *stack_b_head = temp;
  (*stack_b_head)->next = old_head;
  write(1, "rrb\n", 4);
}

void rrr(t_stack **stack_a_head, t_stack **stack_b_head)
{
  rra(stack_a_head);
  rrb(stack_b_head);
  write(1, "rrr\n", 4);
}
