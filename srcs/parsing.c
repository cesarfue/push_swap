/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/19 19:43:13 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*args_to_list(int argc, char **argv)
{
	t_lst		*la;
	t_lst		*new;
	int			val;
	int			i;

	la = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		if (!val || val > INT_MAX || val < INT_MIN)
			return (NULL);
		new = lstnew(val);
		if (new == NULL)
			return (NULL);
		lstadd_back(&la, new);
		i++;	
	}
	return (la);
}


t_lst	*init_lb(t_lst **la)
{
	t_lst	*lb;
	t_lst	*tmp;
	t_lst	*new;
	t_lst	*last;

	lb = NULL;
	last = NULL;
	tmp = *la;
	while (*la)
	{
		new = malloc(sizeof(t_lst));
		if (!new)
			return (NULL);
		new->next = NULL;
		if (last == NULL)
			lb = new;
		else
			last->next = new;
		last = new;
		*la = (*la)->next;
	}
	*la = tmp;
	return (lb);
}
