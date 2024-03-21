#include "push_swap.h"
#include <time.h>

int main(int ac, char **av)
{
    t_stack *new;
    t_stack *temp;
    t_stack *head;
    /*int *res;
    int *arr = ft_parse(ac, av);
    if (ac == 5)
        res = args_4(ac, arr);
    if (ac == 4)
        res = args_3(ac, arr);
    if (ac == 3)
        res = args_2(ac, arr);
    for (int i = 0 ; i < ac - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);*/
    
    int *arr = ft_parse(ac, av);
    int *res = args(ac , arr);  
}