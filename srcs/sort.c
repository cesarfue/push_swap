/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:35:40 by cesar             #+#    #+#             */
/*   Updated: 2024/02/17 08:45:50 by cesar            ###   ########.fr       */
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

void	check_is_first(t_lst **lst, t_lst *first)
{
	if ((*lst)->is_first == 0)
		return ;
	(*lst)->is_first = 0;
	if ((*lst)->next)
		(*lst)->next->is_first = 1;
	else
		first->is_first = 1;
}

void	set_is_first(t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	(*lst)->is_first = 1;
	*lst = (*lst)->next;
	while (*lst)
	{
		(*lst)->is_first = 0;
		*lst = (*lst)->next; 
	}
	*lst = tmp;
}

void	count_sort_to_b(t_lst **la, t_lst **lb)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *la;
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (tmp)
	{
		count[tmp->lsd]++;
		tmp = tmp->next;
	}
	tmp = *la;
	i = -1;
	set_is_first(la);
	while (++i < 10)
	{
		while (count[i] > 0)
		{
			if (*la && (*la)->lsd == i)
			{
				check_is_first(la, tmp);
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

void	count_sort_to_a(t_lst **lb, t_lst **la)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *lb;
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (tmp)
	{
		count[tmp->lsd]++;
		tmp = tmp->next;
	}
	tmp = *lb;
	i = 10;
	set_is_first(lb);
	while (--i >= 0)
	{
		while (count[i] > 0)
		{
			if (*lb && (*lb)->lsd == i)
			{
				check_is_first(lb, tmp);
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
	int		max;

	max = get_largest(*la);
	iterations = intlen(max);
	power = 1;
	while (iterations >= 0 && is_sorted(*la) == 0)
	{
		get_lsd(la, power);
		count_sort_to_b(la, lb);
		// show(*lb, *la);
		power *= 10;
		get_lsd(lb, power);
		count_sort_to_a(lb, la);
		// ra(la);
		// show(*la, *lb);
		power *= 10;
		iterations--;
	}
}
