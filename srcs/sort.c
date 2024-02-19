/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 16:49:52 by cesar            ###   ########.fr       */
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

void	count_sort_to_b(t_lst **la, t_lst **lb, int *count, int iter, int size)
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
			go_to('a', la, 0, i, size);
			check_is_first(la, first);
			pb(lob, la);
			size--;
			count[i]--;
		}
		if (iter >= 1)
			go_to('a', la, 1, 1, size);
	}
}

void	count_sort_to_a(t_lst **lb, t_lst **la, int *count, int size)
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
			go_to('b', lb, 0, i, size);
			check_is_first(lb, first);
			pa(la, lb);
			size--;
			count[i]--;
		}
		go_to('b', lb, 1, 1, size);
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
		count_sort_to_b(la, lb, count, iter, size);
		power *= 10;
		iter++;
		get_lsd(lb, power);
		count = set_array(*lb, count);
		count_sort_to_a(lb, la, count, size);
		power *= 10;
	}
	free(count);
}
