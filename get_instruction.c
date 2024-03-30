#include "push_swap.h"
#include "get_next_line.h"

int is_valid_arg(char *str)
{
    int i;

    i = 0;
    if (ft_strlen(str) != 3 && ft_strlen(str) != 4)
        return (-1);
    char *args[]= {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
    while (i < 11)
    {
        if (strncmp(str, args[i], ft_strlen(args[i])) == 0)
            return (0);
        i++;
    }
    return (-1);
}
int get_instruction(t_stack **head, t_stack **b_head)
{
    char *line;
    int i;

    i = 0;
    while (1)
    {
        line = get_next_line(0);
        if (line == NULL || is_valid_arg(line) < 0)
        {
            if (line == NULL)
                break;
            write (2, "Error\n", 6);
            return (-1);
        }
        apply_instruction(head, b_head, line);
        free(line);
    }
    if (*b_head != NULL)
        checker_error_handle(head, b_head);
    return (0);
}