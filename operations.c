#include "push_swap.h"

void args(int len, t_stack **head)
{
    if (len == 2)
        return (args_2(len, head));
    if (len == 3)
        return (args_3_new(len, head));
    if (len == 4)
        return (args_4_new(len, head));
    if (len == 5)
        return (args_5_new(len, head));
    if (len > 5)
        return (args_s(len, head));
}
void args_2(int len, t_stack **head)
{
    int tmp;

    tmp = 0;
    if ((*head)->data > (*head)->next->data)
    {
        tmp = (*head)->data;
        (*head)->data = (*head)->next->data;
        (*head)->next->data = tmp;
        write (1, "sa", 2);
    }
}

void args_3_new(int len, t_stack **head)
{
    int max_value_index;
    int max_value;

    max_value_index = get_max_index(*head, &max_value);
    if (max_value_index == 0)
    {
        ra(head, 1);
        if ((*head)->data > (*head)->next->data)
            sa(head, 1);
    }
    else if (max_value_index == 1)
    {
        rra(head, 1);
        if ((*head)->data > (*head)->next->data)
            sa(head, 1);
    }
    else
    {
        if ((*head)->data > (*head)->next->data)
            sa(head, 1);
    }
}

void args_4_new(int len, t_stack **head)
{
    t_stack *b_head;
    
    b_head = NULL;
    int min_value;
    int min_value_index;

    min_value_index = get_min_index(*head, &min_value);
    if (min_value_index < (len / 2))
    {
        while ((*head)->data != min_value)
            rra(head, 1);
    }
    else
    {
        while ((*head)->data != min_value)
            ra(head, 1);
    }
    pb(head, &b_head, 1);
    args_3_new(3, head);
    pa(head, &b_head, 1);
}

void args_s(int len, t_stack **head)
{
    t_stack *b_head = NULL;
    int *sorted_array;
    int *arr;
    int max_value;

    arr = stack_to_array((*head), len);
    sorted_array = sort_array(arr, len);
    empty_stack_a(head, &b_head, len, sorted_array);
    empty_stack_b(head, &b_head, len);
}