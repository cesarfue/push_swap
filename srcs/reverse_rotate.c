/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:18:12 by cesar             #+#    #+#             */
/*   Updated: 2024/02/22 12:44:14 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_lst **lst)
{
	t_lst	*blast;
	t_lst	*tmp;

	tmp = *lst;
	blast = lstblast(*lst);
	lstadd_front(lst, lstlast(*lst));
	blast->next = NULL;
	(*lst)->next = tmp;
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

void	reverse_rotate_to(char list, t_lst **lst)
{
	if (list == 'a')
		rra(lst);
	else if (list == 'b')
		rrb(lst);
}
