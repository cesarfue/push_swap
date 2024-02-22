/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:39:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/22 12:42:58 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_lst *lst)
{
	int	tmp;

	if (!lst || !lst->next)
		return ;
	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}

void	sa(t_lst **la)
{
	swap(*la);
	ft_printf("sa\n");
}

void	sb(t_lst **lb)
{
	swap(*lb);
	ft_printf("lb\n");
}

void	ss(t_lst **la, t_lst **lb)
{
	swap(*la);
	swap(*lb);
	ft_printf("ss\n");
}

void	swap_to(char list, t_lst **lst)
{
	if (list == 'a')
		sa(lst);
	else if (list == 'b')
		sb(lst);
}
