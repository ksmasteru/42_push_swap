#include "../includes/push_swap.h"

void free_list(t_stack *head, int index)
{
    t_stack *tmp;
    t_stack *nexto;

    tmp = head;
    while (tmp != NULL)
    {
        nexto = tmp->next;
        free(tmp);
        tmp = nexto;
    }
    if (index == 2)
    {
        write (2, "Error\n", 6);
        exit(1);
    }
}

void free_2d_str(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free (str);
}

void checker_error_handle(t_stack **head, t_stack **b_head)
{
  free_list(*head, 0);
  free_list(*b_head, 0);
  write (1, "KO\n", 3);
  exit(0);
}
int ft_error(int *values, t_stack *head, int index)
{
    t_stack *tmp;
    t_stack *nexto;

    tmp = head;
    if (values != NULL)
        free(values);
    while (tmp != NULL)
    {
        nexto = tmp->next;
        free(tmp);
        tmp = nexto;
    }
    if (index == 1)
        print_error(ANSI_COLOR_RED"Error\n");
    if (index == 2)
        print_error(ANSI_COLOR_RED"Error\n");
    exit(1);
}






