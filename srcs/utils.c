/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:52 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 19:49:42 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(void **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		if (tab[i])
			free(tab[i++]);
	}
	free(tab);
}

void	*tabjoin(char **str, int *size)
{
	int		*data;

	*size = 0;
	data = NULL;
	while (str[*size])
	{
		data = ft_realloc(&data, *size * sizeof(int), ((*size) + 1) * sizeof(int));
		if (!data)
			return (freetab((void **)str, *size), NULL);
		data[*size] = ft_atoi(str[*size]);
		free(str[(*size)++]);
	}
	free(str);
	return (data);
}

size_t	intlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	check_dups(t_lst **la)
{
	t_lst	*i;
	t_lst	*j;

	i = *la;
	j = *la;
	while (i)
	{
		while (j)
		{
			if (j->val == i->val && j != i)
				return (1);
			j = j->next;
		}
		j = *la;
		i = i->next;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		x;
	long	nb;

	i = 0;
	x = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x *= -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (NULL);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (LONG_MAX / 10 < nb || LONG_MAX - (str[i] - '0') < nb * 10)
			return (ft_oversign(x));
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb * x);
}

