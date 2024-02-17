/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/17 16:46:11 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_lst *la, t_lst *lb)
{
	t_lst	*tmpa;
	// t_lst	*tmpb;

	tmpa = la;
	// tmpb = lb;
	while (la || lb)
	{
		printf("%d[%d], %d\n", la->val, la->lsd, la->is_first);
		la = la->next;
		// lb = lb->next; 
	}
	printf("\n");
	la = tmpa;
	// lb = tmpb;
}

void	showcount(int *count)
{
	int	i; 

	i = 0;
	while (i < 10)
		printf("%d ", count[i++]);
	printf("\n");
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

void	count_sort_to_b(t_lst **la, t_lst **lb, int *count)
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
		while (*la && (*la)->is_first == 0)
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
	ssize_t power;
	int		iterations;
	int		*count;
	int		sum;

	iterations = get_largest(*la);
	power = 1;
	count = init_array();
	while (iterations >= 0 && is_sorted(*la) == 0)
	{
		get_lsd(la, power);
		count = set_array(*la, count);
		sum = countsum(count);
		if (sum == 1)
			{
				ra(la); 
				if (is_sorted(*la))
					return ; 
			}
		count_sort_to_b(la, lb, count);
		power *= 10;
		get_lsd(lb, power);
		count = set_array(*lb, count);
		count_sort_to_a(lb, la, count);
		power *= 10;
		iterations--;
	}
	free(count);
}
