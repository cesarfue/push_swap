/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/15 09:25:49 by cesar            ###   ########.fr       */
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
	get_indexes(&la);
	lb = init_lb(&la);
	if (!lb)
		quit_app(&la, &lb, 1);
	radix(&la, &lb);
	// insert_to('b', &lb, &la, 3);
	show(la);
	quit_app(&la, &lb, 0); 
	return (0);
}
