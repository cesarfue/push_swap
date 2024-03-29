/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/22 12:55:42 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_dups(t_lst **la)
{
	t_lst	*i;
	t_lst	*j;

	i = *la;
	j = *la;
	while (i)
	{
		while (j)
		{
			if (j->val == i->val && j != i)
				return (1);
			j = j->next;
		}
		j = *la;
		i = i->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*la;
	t_lst	*lb;
	int		size;

	la = NULL;
	lb = NULL;
	if (!argv[1])
		exit(1);
	if (argc == 2)
		la = str_to_lst(argv[1], &size);
	else
		la = args_to_list(argc, argv, &size);
	if (!la)
		quit_app(&la, &lb, 1);
	else if (check_dups(&la) == 1)
		quit_app(&la, &lb, 1);
	else if (is_sorted(la) == 1)
		quit_app(&la, &lb, 0);
	get_rank(&la);
	if (size < 50)
		lil_sort(&la, &lb);
	else
		radix(&la, &lb);
	quit_app(&la, &lb, 0);
	return (0);
}
