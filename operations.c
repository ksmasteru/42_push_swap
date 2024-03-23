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
        if (tmp->data > imax)
        {
            imax = tmp->data;
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
    arr[0] = tail->data;
    arr[1] = tail->prev->data;
    arr[2] = tail->prev->prev->data;
    while (i < 3)
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
        new = ft_lstadd_back(tmp);
        new->data = values[i];
        new->prev = tmp;
        tmp = new;
        i++;
    }
}
int *args(int ac, int *values)
{
    if (ac == 3)
        return (args_2(ac, values));
    if (ac == 4)
        return (args_3(ac, values));
    if (ac == 5)
        return (args_4(ac, values));
    if (ac == 6)
        return (args_5(ac, values));
    if (ac > 6)
        return (args_s(ac, values));
    return (NULL);
}
int *args_2(int ac, int *values)
{
    int tmp;

    tmp = 0;
    if (values[0] > values[1])
    {
        tmp = values[0];
        values[0] = values[1];
        values[1] = tmp;
        write (1, "sa", 2);
    }
    return (values);
}
int *args_3(int ac, int *values)
{
    t_stack *head;
    t_stack *b_head;

    b_head = NULL;
    arr_to_stack(values, ac - 1, &head);
    if ((head->data) > (head->next->data))
        sa(&head);
    if (head->data > head->next->next->data)
        rra(&head);
    pb(&head, &b_head);
    if(head->data > head->next->data)
        sa(&head);
    pa(&head, &b_head);
    print_stack(head);
    return (values);
}

int *args_4(int ac, int *values)
{
    int tmp;
    int temp = 0;
    int *vals;

    t_stack *head;
    t_stack *b_head = NULL;
    t_stack *tail;
    
    arr_to_stack(values, ac - 1, &head);
    tail = head->next->next->next;
    printf("tail data is %d\n", tail->data);


    if (head->data < head->next->data)
        sa(&head);
    if (head->data < tail->data)
        rra(&head);
    if (head->data < tail->data)
        rra(&head);
    pb(&head, &b_head);
    if ((head->data) > (head->next->data))
        sa(&head);
    if (head->data > head->next->next->data)
        rra(&head);
    pb(&head, &b_head);
    if(head->data > head->next->data)
        sa(&head);
    pa(&head, &b_head);
    pa(&head, &b_head);
    ra(&head);
    print_stack(head);
    return (values);
}
int *args_5(int ac, int *values)
{
    t_stack *head;
    t_stack *tail;
    t_stack *b_head = NULL;

    arr_to_stack(values, ac - 1, &head);
    tail = head->next->next->next->next;
    printf("tail data is %d\n", tail->data);
    if ((head->data) > (head->next->data))
        sa(&head);
    if (head->data > tail->data)
        rra(&head);
    if (head->data > tail->data)
        rra(&head);
    pb(&head, &b_head);
    tail = head->next->next->next;
    if(head->data > head->next->data)
        sa(&head);
    if (head->data > tail->data)
        rra(&head);
    if(head->data > tail->data)
        rra(&head);
    pb(&head, &b_head);
    if(head->data > head->next->data)
        sa(&head);
    if(head->data > head->next->next->data)
        rra(&head);
    if (head->data > head->next->next->data)
        rra(&head);

    if(b_head->data < b_head->next->data)
        sb(&b_head);
    pb(&head, &b_head);
    if (b_head->data < b_head->next->next->data)
        rb(&b_head);
    if (b_head->data < b_head->next->data)
        sb(&b_head);
    if (head->data > head->next->data)
        sa(&head);
    pa(&head, &b_head);
    pa(&head, &b_head);
    pa(&head, &b_head);
    print_stack(head);
    return (values);
}
int *args_s(int ac, int *values)
{
    t_stack *head;
    t_stack *tail;
    t_stack *b_head = NULL;
    int *sorted_array;
    int index;
    int i = 0;
    int end_value;
    int end;
    if (ac - 1 > 5 && ac - 1 <= 20)
        end = 3;
    else if (ac - 1 <= 100)
        end = 15;
    else if (ac - 1 <= 500)
        end = 35;
    else
        end = 45;
    int start = 0;
    index = 0;
    int x = 0;
    int len = 0;
    int max_value;
    arr_to_stack(values, ac - 1, &head);
    sorted_array = sort_array(values, ac - 1);
    while (head != NULL)
    {
        if (head->data >= sorted_array[start] && head->data <= sorted_array[end])
        {
            pb(&head, &b_head);
            if (end < ac - 2)
            {
                start++;
                end++;
            }
            if ((b_head->next != NULL) && (b_head->data < b_head->next->data))
                sb(&b_head);
        }
        else if (head->data < sorted_array[start])
        {
            pb(&head, &b_head);
            if (end < ac - 2)
            {
                start++;
                end++;
            }
            rb(&b_head);
            if ((b_head->next != NULL) && (b_head->data < b_head->next->data))
                sb(&b_head);
        }
        else
            rra(&head);
    }
    while (b_head != NULL)
    {
        x = get_max_index(b_head, &max_value);
        len = stack_len(b_head);
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
        pa(&head, &b_head);
    }
    print_stack(head);
    return (NULL);
}
