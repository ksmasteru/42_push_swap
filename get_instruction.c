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
char *get_instruction(t_stack **head, t_stack **b_head)
{
    char *line;
    char *buffer;
    char *holder;
    int i = 0;
    buffer = NULL;
    holder = NULL;
    /*apply each instruction time by time*/
    while (1)
    {
        line = get_next_line(0);
        if (line == NULL || is_valid_arg(line) < 0)
        {
            if (line == NULL)
            {
                //printf("line is null\n");
                break;
            }
            write (2, "Error\n", 6);
            if (buffer != NULL)
                free(buffer);
            return (NULL);
        }
        if (apply_instruction(head, b_head, line) < 0)
        {
            printf("instrcution error at index %d and ins is %s", i, line);
            exit(1);
        }
        /*holder = ft_strjoin(buffer, line);
        if (buffer != NULL)
            free(buffer);
        buffer = NULL;
        free(line);
        buffer = ft_strdup(holder);
        free(holder);
        i++;*/
    }
    return buffer;
}