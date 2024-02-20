/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/20 11:13:35 by cesar            ###   ########.fr       */
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
		// if (o.iter >= 1)
			while (*la && (*la)->is_first == 0)
				ra(la);
		while (count[i] > 0)
		{
			if (*la && (*la)->lsd == i)
			{
				check_is_first(la, first);
				pb(lb, la);
				// if (--o.size == 3 && o.iter == 0 && o.max_iter == 1)
				// 	return (sort_three(la));
				count[i]--;
			}
			else
				ra(la);
		}
	}
}

void	count_sort_to_a(t_lst **lb, t_lst **la, int *count, t_o o)
{
	t_lst	*first;
	int		i;

	first = *lb;
	i = 10;
	set_is_first(lb);
	while (--i >= 0)
	{
		while (*lb && (*lb)->is_first == 0)
			rb(lb);
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
	}
}

void	radix(t_lst **la, t_lst **lb)
{
	t_o		o;
	int		*count;

	o.max_iter = get_largest(*la);
	o.size = lstsize(*la);
	o.power = 1;
	o.iter = 0;
	count = init_array();
	while (is_sorted(*la) == 0)
	{
		get_lsd(la, o.power);
		count = set_array(*la, count);
		if (check_sum(la, countsum(count)) == 1)
			return ;
		count_sort_to_b(la, lb, count, o);
		show(*lb);
		o.power *= 10;
		o.iter++;
		get_lsd(lb, o.power);
		count = set_array(*lb, count);
		count_sort_to_a(lb, la, count, o);
		o.power *= 10;
		show(*la);
	}
	free(count);
}
