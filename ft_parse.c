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
int *ft_parse(int ac, char **av)
{
    int *values;
    if (ac < 2)
        ft_error(NULL, 0);
    int i;

    i = 0;
    values = (int *)malloc(sizeof(int) * (ac - 1));
    if (!values)
        return (NULL);
    while (i < ac - 1)
    {
        // if (check_erros(av[i + 1]) < 0)
        //     ft_error(values, 1);
        if (ft_atoi(av[i + 1]) > 2147483647 || ft_atoi(av[i + 1]) < -2147483648)
        {
            write(1,"Error\n",6);
            exit(1);
        }
        values[i] = ft_atoi(av[i + 1]);
            i++;
    }
    if (check_duplicates(values, ac - 1 ) < 0)
        ft_error(values, 2);
    return (values);
}
