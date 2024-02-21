/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:35:57 by cesar             #+#    #+#             */
/*   Updated: 2024/02/21 09:36:53 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/*	Get last element	*/
t_lst	*lstlast(t_lst *lst)
{
	t_lst *last;

	last = lst; 
	while (last && last->next)
		last = last->next;
	return (last); 
}

/*	Get element before last element	*/
t_lst	*lstblast(t_lst *lst)
{
	t_lst	*blast;

	blast = lst;
	while (blast && blast->next->next)
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
