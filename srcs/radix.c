/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/13 16:33:59 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_lst *lst)
{
	while (lst)
	{
		printf("%d\n", lst->val);
		lst = lst->next;
	}
}

void	get_lsd(t_lst **lst, ssize_t power)
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
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/*	Interate through decimals to send numbers	*/
/*	to the other list, least significant digits first	*/
void	stack_change_la(t_lst **la, t_lst **lb)
{
	int		i;
	int		i_lsd;
	int		size;

	i = 0;
	size = lstsize((*la));
	i_lsd = -1;
	while (++i_lsd <= 9 && size > 0)
	{
		while (i < size)
		{
			if ((*la)->lsd != i_lsd)
			{
				ra(la);
				i++;
			}
			else 
			{
				pb(lb, la);
				// rb(lb);
				size--;
			}
		}
		i = 0;
	}
}

void	stack_change_lb(t_lst **lb, t_lst **la)
{
	int		i;
	int		i_lsd;
	int		size;

	i = 0;
	size = lstsize((*lb));
	i_lsd = -1;
	while (++i_lsd <= 9 && size > 0)
	{
		while (i < size)
		{
			if ((*lb)->lsd != i_lsd)
			{
				rb(lb);
				i++;
			}
			else 
			{
				pa(la, lb);
				// ra(la);
				size--;
			}
		}
		i = 0;
	}
}

void	radix(t_lst **la, t_lst **lb)
{
	ssize_t power;

	power = 1;
	while (is_sorted(*la) == 0 && power < INT_MAX)
	{
		get_lsd(la, power);
		stack_change_la(la, lb);
		// write(1, "\nstack b : \n", 13);
		// show((*lb));
		// write(1, "\n\n", 3);
		power *= 10;
		get_lsd(lb, power);
		stack_change_lb(lb, la);
		// if (is_sorted(*la) == 1)	
		// 	return ;
		// write(1, "\nstack a : \n", 13);
		// show((*la));
		// write(1, "\n\n", 3);
		power *= 10;
	}
}
