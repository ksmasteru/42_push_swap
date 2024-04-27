#include "../includes/push_swap.h"

void increment_border(int *len, int *start, int *end)
{
    if (*end < *len - 1)
    {
        *start = *start + 1;
        *end = *end + 1;
    }
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
int rrr(t_stack **stack_a_head, t_stack **stack_b_head, int is_checker)
{
  rra(stack_a_head, 0);
  rrb(stack_b_head, 0);
  if (is_checker != 0)
    write(1, "rrr\n", 4);
  return (0);
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




