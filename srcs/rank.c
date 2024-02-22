/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:08:08 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/22 12:54:47 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_next_min(t_lst *lst, int min, int max)
{
	int		next_min;
	t_lst	*start;
	
	start = lst;
	next_min = min + 1;
	while (next_min <= max)
	{
		while (lst)
		{
			if (lst->val == next_min)
				return (next_min);
			lst = lst->next;
		}
		next_min++;
		lst = start;
	}
	return (next_min);
}

int	get_max(t_lst *la)
{
	int	max;

	max = INT_MIN;
	while (la)
	{
		if (la->val > max)
			max = la->val;
		la = la->next;
	}
	return (max);
}

void	get_rank(t_lst **la)
{
	int		min;
	int		max;
	int		size;
	t_lst	*start;
	int		rank;
	
	min = get_lowest(*la);
	max = get_max(*la);
	size = lstsize(*la);
	start = *la;
	rank = 0;
	while (rank < size)
	{
		while ((*la)->next && (*la)->val != min)
			*la = (*la)->next;
		(*la)->rank = rank;
		*la = start;
		min = get_next_min(*la, min, max);
		rank++;
	}
	*la = start;
}
