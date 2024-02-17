/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/17 16:32:35 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (check_dups(&la) == 1)
		quit_app(&la, &lb, 1);
	radix(&la, &lb);
	quit_app(&la, &lb, 0); 
	return (0);
}
