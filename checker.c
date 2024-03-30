#include "push_swap.h"
#include "get_next_line.h"

void checker_error_handle(t_stack **head, t_stack **b_head)
{
  free_list(*head, 0);
  free_list(*b_head, 0);
  write (1, "KO", 2);
  exit(0);
}

int apply_instruction(t_stack **head, t_stack **b_head, char *line)
{
  if (strncmp(line, "pa", strlen(line) - 1) == 0)
    return (pa(head, b_head, 0));
  if (strncmp(line, "pb", strlen(line) - 1) == 0)
    return (pb(head, b_head, 0));
  if (strncmp(line, "sa", strlen(line) - 1) == 0)
    return (sa(head, 0));
  if (strncmp(line, "sb", strlen(line) - 1) == 0)
    return (sb(b_head, 0));
  if (strncmp(line, "ss", strlen(line) - 1) == 0)
    return (ss(head, b_head, 0));
  if (strncmp(line, "ra", strlen(line) - 1) == 0)
    return (ra(head, 0));
  if (strncmp(line, "rr", strlen(line) - 1) == 0)
    return (rr(head, b_head, 0));
  if (strncmp(line, "rb", strlen(line) - 1) == 0)
    return (rb(b_head, 0));
  if (strncmp(line, "rra", strlen(line) - 1) == 0)
    return (rra(head, 0));
  if (strncmp(line, "rrb", strlen(line) - 1) == 0)
    return (rrb(b_head, 0));
  if (strncmp(line, "rrr", strlen(line) - 1) == 0)
    return (rrr(head, b_head, 0));
  return (0);
}
int ft_strncmp(char *s1, char *s2, int len)
{
  int i;

  i = 0;

  while (s1[i] && i < len)
  {
    if (s1[i] != s2[i])
      return (1);
    i++;
  }
  return (0);
}

int main(int ac, char **av)
{
  t_stack *head;
  int *values;
  t_stack *b_head;

  head = ft_parse(ac, av);
  int len = stack_len(head);
  values = stack_to_array(head, len);
  if (check_duplicates(values, len) < 0)
      ft_error(values, head, 2);
  free(values);
  if (get_instruction(&head, &b_head) < 0)
  {
    free_list(head, 0);
    free_list(b_head, 0);
    return (0);
  }
  check_sorted_stack(head, 1);
  free_list(head, 0);
  return (0);  
}