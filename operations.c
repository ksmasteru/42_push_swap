#include "push_swap.h"

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
    int temp = 0; // corrected typo from tmp to temp
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
    /* try to return the smallest possible value */
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

    b_head = NULL;// hmm
    //get the smallest onne from stack a and push it to stack b
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
    //push b
    // sort a as 3
    // push a
    // ra if necessary
    // it is about the journey of becoming great discovering onself true potential
    // make a refernce to tail to avoid travel
    t_stack *head;
    t_stack *b_head = NULL;
    t_stack *tail;
    
    arr_to_stack(values, ac - 1, &head);
    tail = head->next->next->next;
    printf("tail data is %d\n", tail->data);

    // get bigest on a push it to b
    if (head->data < head->next->data)
        sa(&head);
    if (head->data < tail->data)
        rra(&head);
    if (head->data < tail->data)
        rra(&head);
    pb(&head, &b_head);
    // elemnts on b fix.
    if ((head->data) > (head->next->data))
        sa(&head);
    if (head->data > head->next->next->data)
        rra(&head);
    pb(&head, &b_head);
    if(head->data > head->next->data)
        sa(&head);
    pa(&head, &b_head);
    // now push the first "biggest to a and ra"
    pa(&head, &b_head);
    ra(&head);
    print_stack(head);
    return (values);
}
int *args_5(int ac, int *values)
{
    // push too big elements to b
    t_stack *head;
    t_stack *tail;
    t_stack *b_head = NULL;

    arr_to_stack(values, ac - 1, &head);
    tail = head->next->next->next->next;
    printf("tail data is %d\n", tail->data);
    // getting 3 smallest and pushing it to b
    if ((head->data) > (head->next->data))
        sa(&head);
    if (head->data > tail->data)
        rra(&head);
    if (head->data > tail->data) //overkill ?
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
    // this next is absolutly bigger than the other two nop
    // items in b should be in descending order
    // so before pushing should be swapped
    if(b_head->data < b_head->next->data)
        sb(&b_head);
    pb(&head, &b_head);
    // make sure that these are in asceding order
    if (b_head->data < b_head->next->next->data)
        rb(&b_head);
    if (b_head->data < b_head->next->data)
        sb(&b_head);
    // now making a ascending then pushing all of b.
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
    int end = 3;
    int start = 0;
    index = 0;
    arr_to_stack(values, ac - 1, &head);
    sorted_array = sort_array(values, ac - 1);
    /*for (int i = 0 ; i < ac - 1 ; i++)
        printf("%d\n", sorted_array[i]);*/
    while (head != NULL)
    {
        if (head->data >= sorted_array[start] && head->data <= sorted_array[end])
        {
            pb(&head, &b_head);
            if (end < 14)
            {
                start++;
                end++;
            }
        }
        else if (head->data < sorted_array[start])
        {
            pb(&head, &b_head);
            rb(&b_head);
        }
        else
            rra(&head);
    }
    print_stack(b_head);
    return (NULL);
}
