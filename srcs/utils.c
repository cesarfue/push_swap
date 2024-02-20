/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:52 by cesar             #+#    #+#             */
/*   Updated: 2024/02/20 23:34:59 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	*init_array(void)
{
	int	*count;
	
	count = malloc(10 * sizeof(int));
	if (count == NULL)
		return (NULL);
	return (count);
}

int	*set_array(t_lst *lst, int *count)
{
	int	i;

	i = 0;
	while (i < 10)
		count[i++] = 0;
	while (lst)
	{
		count[lst->lsd]++;
		lst = lst->next;
	}
	return (count);
}
