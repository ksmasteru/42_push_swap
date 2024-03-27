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
/* test args validity */
char *get_instruction()
{
    char *line;
    char *buffer;
    char *holder;

    buffer = NULL;
    holder = NULL;
    while (1)
    {
        line = get_next_line(0);
        if (line == NULL || is_valid_arg(line) < 0) /* test if arg is valiid*/
        {
            write (2, "Error\n", 6);
            if (buffer != NULL)
                free(buffer);
            return (NULL);
        }
        if (strncmp(line, "end", 3) == 0)
        {
            free(line);
            break;
        }
        holder = ft_strjoin(buffer, line);
        printf("holdr is %p\n", holder);
        if (buffer != NULL)
            free(buffer);
        buffer = NULL;
        printf("line is %p\n", line);
        free(line);
        printf("buffer is %p\n", buffer);
        buffer = ft_strdup(holder); // really beware this next time
        free(holder);
    }
    return buffer;
}