/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:44:03 by cesar             #+#    #+#             */
/*   Updated: 2024/02/22 12:44:26 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_lst **la)
{
	if ((*la)->val > (*la)->next->val)
		sa(la);
}

void	sort_three(t_lst **la)
{
	if ((*la)->val > (*la)->next->val && (*la)->val < (*la)->next->next->val)
		sa(la);
	else if ((*la)->val > (*la)->next->val
		&& (*la)->val > (*la)->next->next->val)
	{
		if ((*la)->next->val < (*la)->next->next->val)
			ra(la);
		else
		{
			ra(la);
			sa(la);
		}
	}
	else if ((*la)->next->val > (*la)->next->next->val)
	{
		if ((*la)->val > (*la)->next->next->val)
			rra(la);
		else
		{
			sa(la);
			ra(la);
		}
	}
}

void	lil_sort(t_lst **la, t_lst **lb)
{
	int	size;

	size = lstsize(*la);
	if (size == 2)
		return (sort_two(la));
	while (size > 3)
	{
		mark_the_one(la);
		go_to_the_one('a', la, size);
		pb(lb, la);
		size--;
	}
	sort_three(la);
	while (*lb)
		pa(la, lb);
}
