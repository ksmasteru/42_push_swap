#include "push_swap.h"
#include <time.h>

int main(int ac, char **av)
{
    t_stack *new;
    t_stack *temp;
    t_stack *head;
    int *values;

    head = ft_parse(ac, av);
    int len = stack_len(head);
    values = stack_to_array(head, len);
    if (check_duplicates(values, len) < 0)
        ft_error(values, 2);
    free(values);
    args(len , &head);
    free_list(head, 0);
}