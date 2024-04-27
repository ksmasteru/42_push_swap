/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:02:39 by hes-saqu          #+#    #+#             */
/*   Updated: 2024/04/27 20:03:23 by hes-saqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(int *values, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (values[i] > values[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sorted_stack(t_stack *head, int is_checker)
{
	int		is_sorted;
	t_stack	*tmp;

	is_sorted = 0;
	tmp = head;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
		{
			is_sorted = -1;
			break ;
		}
		tmp = tmp->next;
	}
	if (is_sorted == -1 && is_checker != 0)
		write(1, "KO\n", 3);
	else if (is_sorted == 0 && is_checker != 0)
		write(1, "OK\n", 3);
	return (is_sorted);
}

t_stack	*get_tail(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
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

int	scan_tail(int val, t_stack *tail)
{
	int	arr[3];
	int	index;
	int	i;

	i = 0;
	index = -1;
	arr[0] = (tail->data);
	arr[1] = (tail->prev->data);
	arr[2] = (tail->prev->prev->data);
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
