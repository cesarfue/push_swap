/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:22:14 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 11:30:49 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lstnew(int val)
{
	t_lst	*lst;

	lst = malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->val = val;
	lst->next = NULL;
	return (lst);
}

void	lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

t_lst	*lstlast(t_lst *lst)
{
	t_lst *last;

	last = lst; 
	while (last)
		last = last->next;
	return (last); 
}

t_lst	*lstblast(t_lst *lst)
{
	t_lst	*blast;

	blast = lst;
	while (blast->next->next)
		blast = blast->next;
	return (blast);
}

void	lstadd_front(t_lst **lst, t_lst *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	lstfree(t_lst **lst)
{
	t_lst	*tmp;

	if (!*lst || !lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
