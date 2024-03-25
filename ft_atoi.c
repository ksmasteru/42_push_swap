#include "push_swap.h"

long ft_atoi(char *str)
{
    int i;
    int sign;
    long num;

    sign = 1;
    num = 0;
    i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    if (!str[i])
        return (LONG_MAX - 3);
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
         if (((num *= 10) > INT_MAX))
            return(LONG_MAX - 3);
         num += str[i++] - 48;
         if (str[i] == '\0')
            return (num * sign);
    }
    if (str[i])
        return (LONG_MAX - 3);
    return (-1);
}