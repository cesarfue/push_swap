/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/15 08:36:53 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_lst *lst)
{
	while (lst)
	{
		printf("%d[%d]\n", lst->val, lst->lsd);
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

void	count_sort(char list, t_lst **src, t_lst **dest, int max, int size)
{
	t_lst	*tmp;
	int		*count;
	int		i;

	i = 0;
	tmp = *src;
	count = init_array(max);
	if (!count)
		return (free(count), quit_app(src, dest, 1));
	while (tmp)
	{
		count[tmp->lsd]++;
		tmp = tmp->next;
	}
	while (++i < size)
		count[i] += count[i - 1];
	get_indexes(src);
	while (*src)
	{
		i = count[(*src)->lsd]--;
		insert_to(list, dest, src, i);
		*src  = (*src)->next;
	}
}


void	radix(t_lst **la, t_lst **lb)
{
	ssize_t power;
	int		iterations;
	int		size;
	int		max;

	size = lstsize((*la));
	max = get_largest(*la);
	iterations = intlen(max);
	power = 1;
	while (iterations >= 0)
	{
		get_lsd(la, power);
		show(*la);
		count_sort('b', la, lb, max, size);
		power *= 10;
		get_lsd(lb, power);
		count_sort('a', lb, la, max, size);
		power *= 10;
		iterations--;
	}
}
