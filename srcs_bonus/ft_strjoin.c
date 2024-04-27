/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hes-saqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:58:26 by hes-saqu          #+#    #+#             */
/*   Updated: 2023/12/09 23:34:06 by hes-saqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*ft_strdup_n(char *s1)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strjoin_null(char *s1, char *s2)
{
  if (!s1 && !s2)
    return (NULL);
  if (!s1)
    return (ft_strdup_n(s2));
  if (!s2)
    return (ft_strdup_n(s1));
return (NULL);
} 
char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_lent;
	int		s2_lent;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (ft_strjoin_null(s1, s2));
	s1_lent = ft_strlen(s1);
	s2_lent = ft_strlen(s2);
	str = (char *)malloc((s1_lent + s2_lent + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	return (str);
}
