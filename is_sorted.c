#include "push_swap.h"

int is_sorted(int *values, int len)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while(j < len)
        {
            if (values[i] > values[j])
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}