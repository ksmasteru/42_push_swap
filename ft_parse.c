#include "push_swap.h"

void print_error(char *str)
{
    write(2, str, strlen(str));
}
void free_2d_str(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free (str);
}
int    link_numbers(char **num_str, int x, t_stack **tmp)
{
    long number;
    int j;
    t_stack *new;

    j = 0;
    number = 0;
    while (num_str[j] != NULL)
    {
        number = ft_atoi(num_str[j]);
        if (number > INT_MAX || number < INT_MIN)
            return(-1);
        if (x == 0)
        {
            ((*tmp)->data) = number;
            x++;
            j++;
            continue;
        }
        new = ft_lstadd_back(*tmp, number);
        *tmp = new;        
        j++;
    }
    return (0);
}
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
int ft_error(int *values, int index)
{
    if (values != NULL)
        free(values);
    if (index == 0)
        print_error(ANSI_COLOR_RED"Error\n");
    if (index == 1)
        print_error(ANSI_COLOR_RED"Error\n");
    if (index == 2)
        print_error(ANSI_COLOR_RED"Error\n");
    exit(1);
}
int check_erros(char *str)
{
    int i;
    i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while ((str[i] && str[i] >= '0' && str[i] <= '9') || ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) || str[i] == '+' || str[i] == '-'))
    {
        if (str[i] == '-' || str[i] == '+')
        {
            if (!(str[i + 1] <= '9' && str[i + 1] >= '0'))
                return (-1);
        }
        i++;
    }
    if (str[i] == '\0')
        return (0);
    else
        return (-1);  
}

int check_duplicates(int* values, int size)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
        if (values[i] == values[j++])
            return (-1);
        }
        i++;
    }
    return (0);
}
t_stack *ft_parse(int ac, char **av)
{
    t_stack *a_head;
    t_stack *tmp;
    char **num_str;
    int i;
    int x;

    x = 0;
    i = 0;
    a_head = ft_lst_new(0);
    tmp = a_head;
    while (i < ac - 1)
    {
        num_str = ft_split(av[i + 1], 32);
        if (num_str == NULL)
            free_list(a_head, 2);
        if (link_numbers(num_str, x++, &tmp) < 0) /*here for x*/
        {
            free_2d_str(num_str);
            free_list(a_head, 2);
        }   
        free_2d_str(num_str);
        i++;
    }
    return (a_head);
}
