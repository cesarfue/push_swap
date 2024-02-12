/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:40:11 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 10:04:33 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_lst **lst)
{
	t_lst *tmp;

	tmp = *lst;
	*lst = (*lst)->next; 
	lstadd_back(lst, tmp);
	tmp->next = NULL;
}

void	ra(t_lst **la)
{
	rotate(la); 
	ft_printf("ra\n");
}

void	rb(t_lst **lb)
{
	rotate(lb); 
	ft_printf("rb\n");
}

void	rr(t_lst **la, t_lst **lb)
{
	rotate(la); 
	rotate(lb);
	ft_printf("rr\n");
}