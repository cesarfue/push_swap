/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/16 17:25:45 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int argc, char **argv)
{
	t_lst	*la;
	t_lst	*lb;

	la = NULL;
	lb = NULL;
	if (!argv[1] || argc < 2)
		quit("Error\n");
	else
		la = args_to_list(argc, argv);
	if (!la)
		quit_app(&la, &lb, 1); 
	radix(&la, &lb);
	// set_is_first(&la);
	// show(la, lb);
	// ra(&la);
	// show(la, lb);
	// while (la->is_first == 0)
	// 	rra(&la);
	// show(la, lb);
	quit_app(&la, &lb, 0); 
	return (0);
}
