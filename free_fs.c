#include "push_swap.h"

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




