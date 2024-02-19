/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 17:18:44 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	count_sort_to_b(t_lst **la, t_lst **lb, int *count, int iter)
{
	t_lst	*first;
	int		i;

	first = *la;
	i = -1;
	set_is_first(la);
	while (++i < 10)
	{
		while (count[i] > 0)
		{
			if (*la && (*la)->lsd == i)
			{
				check_is_first(la, first);
				pb(lb, la);
				count[i]--;
			}
			else
				ra(la);
		}
		if (iter >= 1)
		{
			while (*la && (*la)->is_first == 0)
				ra(la);
		}
	}
}

void	count_sort_to_a(t_lst **lb, t_lst **la, int *count)
{
	t_lst	*first;
	int		i;

	first = *lb;
	i = 10;
	set_is_first(lb);
	while (--i >= 0)
	{
		while (count[i] > 0)
		{
			if (*lb && (*lb)->lsd == i)
			{
				check_is_first(lb, first);
				pa(la, lb);
				count[i]--;
			}
			else
				rb(lb);
		}
		while (*lb && (*lb)->is_first == 0)
			rb(lb);
	}
}

void	radix(t_lst **la, t_lst **lb)
{
	ssize_t power;
	int		iter;
	int		*count;
	int		size;

	size = lstsize(*la);
	power = 1;
	count = init_array();
	iter = 0;
	while (is_sorted(*la) == 0)
	{
		get_lsd(la, power);
		count = set_array(*la, count);
		if (check_sum(la, countsum(count)) == 1)
			return ;
		count_sort_to_b(la, lb, count, iter);
		power *= 10;
		iter++;
		get_lsd(lb, power);
		count = set_array(*lb, count);
		count_sort_to_a(lb, la, count);
		power *= 10;
	}
	free(count);
}
