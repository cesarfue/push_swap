/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/21 17:01:40 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	only_p(t_lst *la, int i, int size, int shift)
{
	while (i < size && ((la->val >> shift) & 1) == 0)
	{
		i++;
		la = la->next;
	}
	if (i == size)
		return (1);
	return (0);
}

void	sort(t_lst **la, t_lst **lb, int shift)
{
	int		size;
	int		i;

	i = 0;
	size = lstsize(*la);
	while (i < size)
	{
		if ((((*la)->val >> shift) & 1) == 0)
		{
			if (only_p(*la, i, size, shift) == 1)
				break ;
			pb(lb, la);
		}
		else
			ra(la); 
		i++;
	}
	while (*lb)
		pa(la, lb);
}

void	radix(t_lst **la, t_lst **lb)
{
	int	shift;

	shift = 0;
	while (is_sorted(*la) == 0)
	{
		sort(la, lb, shift);
		shift++;
	}
}
