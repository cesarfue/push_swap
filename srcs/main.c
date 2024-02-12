/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 11:19:23 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_lst **la, t_lst **lb)
{

	// sa(*la);
	// pb(lb, la);
	rra(la);
	t_lst *tmpa = *la;
	t_lst *tmpb = *lb;
	printf("\npile a :  ");
	while (tmpa)
	{
		printf("%d ", tmpa->val);
		tmpa = tmpa->next;
	}
	printf("\npile b :  ");
	tmpb = *lb;
	while (tmpb)
	{
		printf("%d ", tmpb->val);
		tmpb = tmpb->next;
	}
}

int	main(int argc, char **argv)
{
	t_lst	*la;
	t_lst	*lb;

	if (!argv[1] || argc < 2)
		quit("Wrong arguments");
	else
		la = args_to_list(argc, argv);
	if (!la)
		quit_app(&la, &lb, 1); 
	lb = NULL;
	show(&la, &lb);
	quit_app(&la, &lb, 0); 
	return (0);
}
