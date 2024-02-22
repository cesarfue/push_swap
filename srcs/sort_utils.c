/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:27:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/22 12:45:15 by cefuente         ###   ########.fr       */
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

int	cost(t_lst *lst, int size)
{
	int	cost;

	cost = 0;
	while (lst && (lst->is_theone == 0))
	{
		lst = lst->next;
		cost++;
	}
	if (cost <= size / 2)
		return (0);
	return (1);
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

void	go_to_the_one(char list, t_lst **lst, int size)
{
	void	(*r)(char, t_lst **);

	if (cost(*lst, size) == 0)
		r = rotate_to;
	else
		r = reverse_rotate_to;
	while (*lst && (*lst)->is_theone == 0)
		r(list, lst);
}
