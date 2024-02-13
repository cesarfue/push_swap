/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/13 14:21:08 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int argc, char **argv)
{
	t_lst	*la;
	t_lst	*lb;

	la = NULL;
	if (!argv[1] || argc < 2)
		quit("Error\n");
	else
		la = args_to_list(argc, argv);
	if (!la)
		quit_app(&la, 1); 
	// la = la->next;
	lb = NULL;
	radix(&la, &lb);
	// printf("la is \n");
	// show(la);
	quit_app(&la, 0); 
	return (0);
}
