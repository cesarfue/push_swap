/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:40:11 by cesar             #+#    #+#             */
/*   Updated: 2024/02/16 13:58:12 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	*lst = (*lst)->next; 
	tmp->next = NULL;
	lstadd_back(lst, tmp);
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

void	rotate_to(char list, t_lst **lst)
{
	if (list == 'a')
		ra(lst);
	else if (list == 'b')
		rb(lst);
}