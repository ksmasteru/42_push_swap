#include "push_swap.h"

int get_min_index(t_stack *head, int *min_value)
{
    int imin;
    t_stack *tmp;
    int i;
    int j;

    j = 0;
    i = 0;
    tmp = head;
    imin = head->data;
    *min_value = imin;
    while (tmp != NULL)
    {
        if ((tmp->data) < imin)
        {
            
            imin = (tmp->data);
            *min_value = imin;
            i = j;
        }
        tmp = tmp->next;
        j++;
    }
    return (i);
}
int get_max_index(t_stack *head, int *max_value)
{
    int imax;
    t_stack *tmp;
    int i;
    int j;

    j = 0;
    i = 0;
    tmp = head;
    imax = head->data;
    *max_value = imax;
    while (tmp != NULL)
    {
        if ((tmp->data) > imax)
        {
            imax = (tmp->data);
            *max_value = imax;
            i = j;
        }
        tmp = tmp->next;
        j++;
    }
    return (i);
}
void arr_to_stack(int *values, int size,  t_stack **head)
{
    t_stack *tmp;
    t_stack *new;
    int i;

    i = 0;
    while (i < size)
    {
        if (i == 0)
        {
            *head = ft_lst_new(values[i]);
            i++;
            tmp = *head;
            continue;
        }
        new = ft_lstadd_back(tmp, values[i]);
        new->prev = tmp;
        tmp = new;
        i++;
    }
}
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
void args_3(int len, t_stack **head)
{
    t_stack *b_head;

    b_head = NULL;
    if (((*head)->data) > ((*head)->next->data))
        sa(head, 1);
    if ((*head)->data > (*head)->next->next->data)
        rra(head, 1);
    pb(head, &b_head, 1);
    if((*head)->data > (*head)->next->data)
        sa(head, 1);
    pa(head, &b_head, 1);
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

void args_4(int len, t_stack **head)
{
    t_stack *b_head = NULL;
    t_stack *tail;
    
    tail = (*head)->next->next->next;
    if ((*head)->data < (*head)->next->data)
        sa(head, 1);
    if ((*head)->data < tail->data)
        rra(head, 1);
    if ((*head)->data < tail->data)
        rra(head, 1);
    pb(head, &b_head, 1);
    if (((*head)->data) > ((*head)->next->data))
        sa(head, 1);
    if ((*head)->data > (*head)->next->next->data) 
        rra(head, 1);
    pb(head, &b_head, 1);
    if((*head)->data > (*head)->next->data)
        sa(head, 1);
    pa(head, &b_head, 1);
    pa(head, &b_head, 1);
    ra(head, 1);
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
    args_3_new(3, head);/* is len 2 or 3 ?*/
    pa(head, &b_head, 1);
}

void swap_args_5_1(t_stack **head, int len, t_stack **tail, t_stack **b_head)
{
    (*tail) = (*head)->next->next->next->next;
    if (((*head)->data) > ((*head)->next->data))
        sa(head, 1);
    if ((*head)->data > (*tail)->data)
        rra(head, 1);
    if ((*head)->data > (*tail)->data)
        rra(head, 1);
    pb(head, b_head, 1);
    (*tail) = (*head)->next->next->next;
    if((*head)->data > (*head)->next->data)
        sa(head, 1);
    if ((*head)->data > (*tail)->data)
        rra(head, 1);
    if((*head)->data > (*tail)->data)
        rra(head, 1);
    pb(head, b_head, 1);
    if((*head)->data > (*head)->next->data)
        sa(head, 1);
}
void args_5(int len, t_stack **head)
{
    t_stack *tail;
    t_stack *b_head = NULL;

    swap_args_5_1(head, len, &tail, &b_head);
    if((*head)->data > (*head)->next->next->data)
        rra(head, 1);
    if ((*head)->data > (*head)->next->next->data)
        rra(head, 1);
    if(b_head->data < b_head->next->data)
        sb(&b_head, 1);
    pb(head, &b_head, 1);
    if (b_head->data < b_head->next->next->data)
        rb(&b_head, 1);
    if (b_head->data < b_head->next->data)
        sb(&b_head, 1);
    if ((*head)->data > (*head)->next->data)
        sa(head, 1);
    pa(head, &b_head, 1);
    pa(head, &b_head, 1);
    pa(head, &b_head, 1);
}
/*better algo for 5 ints*/
void args_5_new(int len, t_stack **head)
{
    int min_value;
    int min_value_index;
    int i;
    t_stack *b_head;

    b_head = NULL;
    min_value_index = get_min_index(*head , &min_value);
    if (min_value_index < (len / 2))
    {
        while ((*head)->data != min_value)
            ra(head, 1);
    }
    else
    {
        while ((*head)->data != min_value)
            rra(head, 1);
    }
    pb(head, &b_head, 1);
    args_4_new(len - 1, head);
    pa(head, &b_head, 1);
}
int get_end(int len)
{
    int end;

    if (len > 5 && len <= 20)
        end = 3;
    else if (len <= 100)
        end = 15;
    else if (len <= 500)
        end = 25;
    else
        end = 45;
    return (end);
}
void increment_border(int *len, int *start, int *end)
{
    if (*end < *len - 1)
    {
        *start = *start + 1;
        *end = *end + 1;
    }
}


void empty_stack_a(t_stack **head, t_stack **b_head, int len, int *sorted_array)
{
    int start;
    int end;
    int min_value;

    min_value = 0;
    start = 0;
    end = get_end(len);
    while ((*head) != NULL)
    {
        if ((*head)->data >= sorted_array[start] && (*head)->data <= sorted_array[end])
            {
                pb(head, b_head, 1);
                increment_border(&len, &start, &end);
                if (((*b_head)->next != NULL) && ((*b_head)->data < (*b_head)->next->data))
                    sb(b_head, 1);
            }
        else if ((*head)->data < sorted_array[start])
        {
            pb(head, b_head, 1);
            increment_border(&len, &start, &end);
                rb(b_head, 1); 
            if (((*b_head)->next != NULL) && ((*b_head)->data < (*b_head)->next->data))
                sb(b_head, 1);
        }
        else
            ra(head, 1);
    }
}
void empty_stack_b(t_stack **head, t_stack **b_head, int len)
{
    int max_value;
    int x;

    x = 0;
    max_value = 0;
    while ((*b_head) != NULL)
    {
        x = get_max_index(*b_head, &max_value);
        if (x != 0)
        {
            if (x < len / 2)
            {
                while ((*b_head)->data != max_value)
                    rb(b_head, 1);
            }
            else
            {
                while ((*b_head)->data != max_value)
                    rrb(b_head, 1);
            }
        }
        pa(head, b_head, 1);
        len--;
    }
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