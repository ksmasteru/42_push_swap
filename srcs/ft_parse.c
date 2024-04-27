/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:01:47 by hes-saqu          #+#    #+#             */
/*   Updated: 2024/04/27 22:01:48 by hes-saqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	link_numbers(char **num_str, int x, t_stack **tmp, t_stack **head)
{
	long	number;
	int		j;
	t_stack	*new;

	j = 0;
	number = 0;
	while (num_str[j] != NULL)
	{
		number = ft_atoi(num_str[j]);
		if (number > INT_MAX || number < INT_MIN)
			return (-1);
		if (x == 0)
		{
			*tmp = ft_lst_new(number);
			*head = *tmp;
			x++;
			j++;
			continue ;
		}
		new = ft_lstadd_back(*tmp, number);
		*tmp = new;
		j++;
	}
	return (0);
}

int	check_duplicates(int *values, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (values == NULL)
		return (-1);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j++])
				return (-1);
		}
		i++;
	}
	return (0);
}

t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*a_head;
	t_stack	*tmp;
	char	**num_str;
	int		i;
	int		x;

	x = 0;
	i = 0;
	a_head = NULL;
	tmp = a_head;
	while (i < ac - 1)
	{
		num_str = ft_split(av[i + 1], 32);
		if (num_str == NULL)
			free_list(a_head, 2);
		if (link_numbers(num_str, x++, &tmp, &a_head) < 0)
		{
			free_2d_str(num_str);
			free_list(a_head, 2);
		}
		free_2d_str(num_str);
		i++;
	}
	return (a_head);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	num;

	num = 0;
	i = 0;
	sign = atoi_get_sign(&str);
	if (!str[i])
		return (LONG_MAX - 3);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		if (num > INT_MAX)
			return (LONG_MAX - 3);
		num += str[i++] - 48;
		if (str[i] == '\0')
			return (num * sign);
	}
	if (str[i])
		return (LONG_MAX - 3);
	return (-1);
}

int	atoi_get_sign(char **str)
{
	int		sign;
	char	*stri;
	int		i;

	i = 0;
	stri = *str;
	sign = 1;
	while (stri[i] == 32 || (stri[i] >= 9 && stri[i] <= 13))
		i++;
	if (stri[i] == '+' || stri[i] == '-')
	{
		if (stri[i] == '-')
			sign *= -1;
		i++;
	}
	*str = *str + i;
	return (sign);
}
