/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:38:58 by cesar             #+#    #+#             */
/*   Updated: 2024/02/13 16:00:15 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_lst **dest, t_lst **src)
{
	t_lst *tmp;

	if (*src == NULL)
		return ;
	tmp = *src;
	*src = (*src)->next; 
	tmp->next = NULL;
	lstadd_front(dest, tmp);
}

void	pa(t_lst **la, t_lst **lb)
{
	push(la, lb); 
	ft_printf("pa\n"); 
}

void	pb(t_lst **lb, t_lst **la)
{
	push(lb, la);
	ft_printf("pb\n"); 
}
