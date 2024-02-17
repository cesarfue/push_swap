/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:27:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/17 09:55:25 by cesar            ###   ########.fr       */
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
	return (intlen(ret)); 
}


void	check_is_first(t_lst **lst, t_lst *first)
{
	if ((*lst)->is_first == 0)
		return ;
	(*lst)->is_first = 0;
	if ((*lst)->next)
		(*lst)->next->is_first = 1;
	else
		first->is_first = 1;
}

void	set_is_first(t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	(*lst)->is_first = 1;
	*lst = (*lst)->next;
	while (*lst)
	{
		(*lst)->is_first = 0;
		*lst = (*lst)->next; 
	}
	*lst = tmp;
}
