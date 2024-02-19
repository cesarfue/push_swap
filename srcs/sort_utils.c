/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:27:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 17:21:24 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sum(t_lst **la, int sum)
{
	if (sum == 1)
	{
		ra(la);
		if (is_sorted(*la))
			return (1);
	}
	return (0);
}

int	is_sorted(t_lst *lst)
{
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	get_largest(t_lst *lst)
{
	int ret;

	ret = INT_MIN;
	while (lst)
	{
		if (lst->val > ret)
			ret = lst->val;
		lst = lst->next;
	}
	return (intlen(ret)); 
}
