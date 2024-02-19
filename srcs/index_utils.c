/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:35:16 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 15:24:13 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
* If the pushed element is also the first one, 
* move "is_first" to the next element
*/
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

/* 
* Set first element of the list as "is_first"
* to keep elements in order when sending to the
* other list
*/
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

/* 
* Calculate whether to use rotate or reverse rotate
* to go to the desired node
*/
int	cost(t_lst *lst, int type, int target, int size)
{
	int	cost;

	cost = 0;
	while (lst && ((type == 0 && (lst->lsd != target))
		|| (type == 1 && (lst->is_first == 0))))
	{
		lst = lst->next;
		cost++;
	}
	if (cost <= size / 2)
		return (0);
	return (1);	
}

/*
* Go to the desired node (type 0 == lsd and type 1 == is_first) 
*/
void	go_to(char list, t_lst **lst, int type, int target, int size)
{
	void (*r)(char, t_lst **);

	if (cost(*lst, type, target, size) == 0)
		r = rotate_to;
	else
		r = reverse_rotate_to;
	while (*lst && ((type == 0 && ((*lst)->lsd != target))
		|| (type == 1 && ((*lst)->is_first == 0))))
		r(list, lst);
}
