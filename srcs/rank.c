/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:08:08 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/22 12:45:28 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_lowest(t_lst *lst)
{
	int	ret;

	ret = INT_MAX;
	while (lst)
	{
		if (lst->val < ret)
			ret = lst->val;
		lst = lst->next;
	}
	return (ret);
}

int	get_max_rank(t_lst *la, int *max)
{
	static int	max = INT_MIN;

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
	int		max;
	int		min;
	int		size;
	t_lst	*start;
	int		rank;

	max = get_max(*la);
	min = get_lowest(*la);
	size = lstsize(*la);
	start = *la;
	rank = 0;
	while (rank < size)
	{
		while ((*la)->val != max)
			la = (*la)->next;
		(*la)->rank = rank;
	}
}
