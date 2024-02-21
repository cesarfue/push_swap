/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/21 14:36:27 by cesar            ###   ########.fr       */
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

void	count_sort_to_b(t_lst **la, t_lst **lb, int *count, t_o o)
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
		while (o.iter >= 1 && *la && (*la)->is_first == 0)
			ra(la);
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
	t_o		o;
	int		*count;

	o.max_iter = intlen(get_largest(*la));
	o.size = lstsize(*la);
	o.power = 1;
	o.iter = 0;
	count = init_array();
	if (!count)
		quit_app(la, lb, 1);
	while (is_sorted(*la) == 0 && o.iter <= o.max_iter + 1)
	{
		get_lsd(la, o.power);
		count = set_array(*la, count);
		count_sort_to_b(la, lb, count, o);
		o.power *= 10;
		o.iter++;
		get_lsd(lb, o.power);
		count = set_array(*lb, count);
		count_sort_to_a(lb, la, count);
		o.power *= 10;
	}
	free(count);
}
