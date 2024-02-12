/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:18:12 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 11:31:02 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*bot;

	tmp = *lst;
	bot = lstlast(*lst);
	// lstadd_front(lst, bot);
	// (*lst)->next = tmp;
}

void	rra(t_lst **la)
{
	reverse_rotate(la); 
	ft_printf("rra\n");
}

void	rrb(t_lst **lb)
{
	reverse_rotate(lb); 
	ft_printf("rrb\n");
}

void	rrr(t_lst **la, t_lst **lb)
{
	reverse_rotate(la); 
	reverse_rotate(lb);
	ft_printf("rrr\n");
}