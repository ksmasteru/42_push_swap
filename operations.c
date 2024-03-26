#include "push_swap.h"

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
t_stack *get_tail(t_stack *head)
{
    t_stack *tmp;
    
    tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

int *sort_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            j++;
        }
        i++;
    }
    return (array);
}
int scan_tail(int val, t_stack *tail)
{

    int arr[3];
    int smallest;
    int index;
    int i;

    i = 0;
    index = -1;
    arr[0] = (tail->data);
    arr[1] = (tail->prev->data);
    arr[2] = (tail->prev->prev->data);
   while (i <3) 
   {
      if (val > arr[i])
      {
        val = arr[i];
        index = i;
      }
      i++;
    }
    return (index);
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
        return (args_3(len, head));
    if (len == 4)
        return (args_4(len, head));
    if (len == 5)
        return (args_5(len, head));
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
        sa(head);
    if ((*head)->data > (*head)->next->next->data)
        rra(head);
    pb(head, &b_head);
    if((*head)->data > (*head)->next->data)
        sa(head);
    pa(head, &b_head);
}

void args_4(int len, t_stack **head)
{
    int tmp;
    int temp = 0;
    int *vals;

    t_stack *b_head = NULL;
    t_stack *tail;
    
    tail = (*head)->next->next->next;
    if ((*head)->data < (*head)->next->data)
        sa(head);
    if ((*head)->data < tail->data)
        rra(head);
    if ((*head)->data < tail->data)
        rra(head);
    pb(head, &b_head);
    if (((*head)->data) > ((*head)->next->data))
        sa(head);
    if ((*head)->data > (*head)->next->next->data)
        rra(head);
    pb(head, &b_head);
    if((*head)->data > (*head)->next->data)
        sa(head);
    pa(head, &b_head);
    pa(head, &b_head);
    ra(head);
}

void swap_args_5_1(t_stack **head, int len, t_stack **tail, t_stack **b_head)
{
    (*tail) = (*head)->next->next->next->next;
    if (((*head)->data) > ((*head)->next->data))
        sa(head);
    if ((*head)->data > (*tail)->data)
        rra(head);
    if ((*head)->data > (*tail)->data)
        rra(head);
    pb(head, b_head);
    (*tail) = (*head)->next->next->next;
    if((*head)->data > (*head)->next->data)
        sa(head);
    if ((*head)->data > (*tail)->data)
        rra(head);
    if((*head)->data > (*tail)->data)
        rra(head);
    pb(head, b_head);
    if((*head)->data > (*head)->next->data)
        sa(head);
}
void args_5(int len, t_stack **head)
{
    t_stack *tail;
    t_stack *b_head = NULL;

    swap_args_5_1(head, len, &tail, &b_head);
    if((*head)->data > (*head)->next->next->data)
        rra(head);
    if ((*head)->data > (*head)->next->next->data)
        rra(head);
    if(b_head->data < b_head->next->data)
        sb(&b_head);
    pb(head, &b_head);
    if (b_head->data < b_head->next->next->data)
        rb(&b_head);
    if (b_head->data < b_head->next->data)
        sb(&b_head);
    if ((*head)->data > (*head)->next->data)
        sa(head);
    pa(head, &b_head);
    pa(head, &b_head);
    pa(head, &b_head);
}
void args_s(int len, t_stack **head)
{
    t_stack *tail;
    t_stack *b_head = NULL;
    int *sorted_array;
    int index;
    int i = 0;
    int end_value;
    int end;
    int *arr;
    if (len > 5 && len <= 20)
        end = 3;
    else if (len <= 100)
        end = 15;
    else if (len <= 500)
        end = 35;
    else
        end = 45;
    int start = 0;
    index = 0;
    int x = 0;
    int max_value;
    arr = stack_to_array((*head), len);
    sorted_array = sort_array(arr, len);
    while ((*head) != NULL)
    {
        if ((*head)->data >= sorted_array[start] && (*head)->data <= sorted_array[end])
        {
            pb(head, &b_head);
            if (end < len - 1)
            {
                start++;
                end++;
            }
            if ((b_head->next != NULL) && (b_head->data < b_head->next->data))
                sb(&b_head);
        }
        else if ((*head)->data < sorted_array[start])
        {
            pb(head, &b_head);
            if (end < len - 1)
            {
                start++;
                end++;
            }
            rb(&b_head);
            if ((b_head->next != NULL) && (b_head->data < b_head->next->data))
                sb(&b_head);
        }
        else
            rra(head);
    }
    while (b_head != NULL)
    {
        x = get_max_index(b_head, &max_value);
        if (x != 0)
        {
            if (x < len / 2)
            {
                while (b_head->data != max_value)
                    rb(&b_head);
            }
            else
            {
                while (b_head->data != max_value)
                    rrb(&b_head);
            }
        }
        pa(head, &b_head);
    }
}
