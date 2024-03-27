#include "push_swap.h"
#include "get_next_line.h"

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
  free(buffer);
  
  return (0);  
}
