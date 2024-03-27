#include "push_swap.h"
#include "get_next_line.h"

/* apply instrcution*/
void checker_error_handle(t_stack **head, t_stack **b_head, char **instructions, int *values)
{
  free_list(*head, 0);
  free_list(*b_head, 0);
  free_2d_str(instructions);
  free(values);
  write (1, "KO", 2);
  exit(0);
}
void check_sorted_stack(t_stack *head, int len)
{
  int *arr;
  int i;

  arr = stack_to_array(head, len);
  if (arr == NULL)
    return ;
  if (is_sorted(arr, len) < 0)
    write (1, "KO", 2);
  else
    write (1, "OK", 2);
  free(arr);
}
int apply_instruction(t_stack **head, t_stack **b_head, char *instruction)
{
  if (strcmp(instruction, "pa") == 0)
    return (pa(head, b_head, 0));
  if (strcmp(instruction, "pb") == 0)
    return (pb(head, b_head, 0));
  if (strcmp(instruction, "sa") == 0)
    return (sa(head, 0));
  if (strcmp(instruction, "sb") == 0)
    return (sb(b_head, 0));
  if (strcmp(instruction, "ss") == 0)
    return (ss(head, b_head, 0));
  if (strcmp(instruction, "ra") == 0)
    return (ra(head, 0));
  if (strcmp(instruction, "rr") == 0)
    return (rr(head, b_head, 0));
  if (strcmp(instruction, "rb") == 0)
    return (rb(b_head, 0));
  if (strcmp(instruction, "rra") == 0)
    return (rra(head, 0));
  if (strcmp(instruction, "rrb") == 0)
    return (rrb(b_head, 0));
  if (strcmp(instruction, "rrr") == 0)
    return (rrr(head, b_head, 0));
  return (0);
}
void apply_instructions(t_stack **head, int len, char *buffer, int *values)
{
  // 2d array of instruction.
  int i;
  char **instructions;
  t_stack *b_head;

  b_head = NULL;
  i = 0;
  instructions = ft_split(buffer, '\n');/*handle malloc ?*/
  free(buffer);
  if (!instructions)
    return ;
  while (instructions[i] != NULL)
  {
      if (apply_instruction(head, &b_head, instructions[i]) < 0)
        checker_error_handle(head, &b_head, instructions, values);
      i++;
  }
  if (b_head != NULL)
    checker_error_handle(head, &b_head, instructions, values);
  free(values);
  free_2d_str(instructions);
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
  char *buffer;
  char *holder;
  char *line;
  t_stack *head;
  int *values;

  head = ft_parse(ac, av);
  int len = stack_len(head);
  values = stack_to_array(head, len);
  if (check_duplicates(values, len) < 0)
      ft_error(values, 2);
  if (is_sorted(values, len) == 0)
  {
      free(values);
      return (0);
  }
  buffer = get_instruction();
  if (buffer == NULL)
    return (0);
  apply_instructions(&head, len, buffer, values);
  check_sorted_stack(head, len);
  free_list(head, 0);
  return (0);  
}
