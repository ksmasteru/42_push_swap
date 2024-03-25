#include "push_swap.h"

// no duplicates
// only numbers
void print_error(char *str)
{
    write(2, str, strlen(str));
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
    exit (1);
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
    t_stack *new;
    char **num_str;
    int *values;
    if (ac < 2)
        ft_error(NULL, 0);
    int i;
    long number;
    int j;

    int x = 0;
    j = 0;
    number = 0;
    i = 0;
    a_head = ft_lst_new(0);
    tmp = a_head;
    while (i < ac - 1)
    {
        j = 0;
        num_str = ft_split(av[i + 1], 32);
        if (num_str == NULL)
        {
            write (2, "Error\n", 6);
            // free the ls.
            exit(1);
        }
        while (num_str[j] != NULL)
        {
            number = ft_atoi(num_str[j]);
            if (number > 2147483647 || number < -2147483648)
            {
                write(1,"Error\n",6);
                exit(1);
            }
            if (x == 0)
            {
                tmp->data = number;
                x++;
                j++;
                continue;
            }
            new = ft_lstadd_back(tmp);
            new->data = number;
            tmp = new;        
            j++;
        }
        i++;
    }
    //print_stack(a_head);
    return (a_head);
}
