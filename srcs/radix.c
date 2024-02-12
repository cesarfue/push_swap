/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 20:06:58 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_lsd(t_lst **lst, int power)
{
	t_lst *tmp;

	tmp = *lst;
	while (*lst)
	{
		(*lst)->lsd = ((*lst)->val / power) % 10;
		*lst = (*lst)->next;
	}
	*lst = tmp;
}

int	is_sorted(t_lst *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/*	Interate through decimals to send numbers	*/
/*	to the other list, least significant digits first	*/
void	stack_change(t_lst **src, t_lst **dest)
{
	int		i;
	int		i_lsd;
	int		size;

	i = 0;
	size = lstsize((*src));
	i_lsd = -1;
	while (++i_lsd <= 9 && size > 0)
	{
		while (i < size)
		{
			if ((*src)->lsd != i_lsd)
			{
				ra(src);
				i++;
			}
			else 
			{
				pb(dest, src);
				rb(dest);
				size--;
			}
		}
		i = 0;
	}
}

void	radix(t_lst **la, t_lst **lb)
{
	int power;

	power = 1;
	while (is_sorted(*la) == 0)
	{
		get_lsd(la, power);
		stack_change(la, lb);
		power *= 10;
		get_lsd(lb, power);
		stack_change(lb, la);
		power *= 10;
	}
}
