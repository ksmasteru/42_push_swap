#include "push_swap.h"
// "   +123" ok
// " a23" not ok
long ft_atoi(char *str)
{
    int i;
    int sign;
    int num;

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
        return (8945612684);
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
         num *= 10;
         num += str[i++] - 48;
         if (str[i] == '\0')
            return (num * sign);
    }
    if (str[i])
        return (6543654656);
    return (-1);
}