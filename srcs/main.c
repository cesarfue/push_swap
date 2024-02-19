/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 13:22:47 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_lst *la)
{
	while (la)
	{
		printf("%d ", la->val);
		la = la->next; 
	}
}

int	main(int argc, char **argv)
{
	t_lst	*la;
	t_lst	*lb;

	la = NULL;
	lb = NULL;
	if (!argv[1])
		exit(1);
	else
		la = args_to_list(argc, argv);
	if (!la)
		quit_app(&la, &lb, 1); 
	else if (check_dups(&la) == 1)
		quit_app(&la, &lb, 1);
	else if (is_sorted(la) == 1)
		quit_app(&la, &lb, 0);
	if (argc <= 4)
		lil_sorts(argc, &la);
	else
		radix(&la, &lb);
	// show(la);
	quit_app(&la, &lb, 0); 
	return (0);
}
