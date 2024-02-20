/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:44:03 by cesar             #+#    #+#             */
/*   Updated: 2024/02/20 10:06:51 by cesar            ###   ########.fr       */
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
	else if ((*la)->val > (*la)->next->val && (*la)->val > (*la)->next->next->val)
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

void	lil_sorts(int size, t_lst **la)
{
	if (size == 2)
		sort_two(la);
	else if (size <= 3)
		sort_three(la);
}