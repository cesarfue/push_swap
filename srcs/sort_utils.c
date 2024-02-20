/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:27:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/20 23:31:46 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (ret); 
}

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

void	mark_the_one(t_lst **lst)
{
	int		lowest;
	t_lst	*tmp;

	lowest = get_lowest(*lst);
	tmp = *lst;
	while (*lst)
	{
		if ((*lst)->val == lowest)
			(*lst)->is_theone = 1;
		else
			(*lst)->is_theone = 0;
		*lst = (*lst)->next;
	}
	*lst = tmp;
}
