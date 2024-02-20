/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:27:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/20 10:10:07 by cesar            ###   ########.fr       */
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

void	go_first(char list, t_lst **lst, int iter)
{
	if (iter == 0 && list == 'a')
		return ;
	while (*lst && (*lst)->is_first == 0)
		rotate_to(list, lst);
}
