/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/21 00:35:58 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show(t_lst *lst)
{
	while (lst)
	{
		printf("%d ", lst->val);
		lst = lst->next; 
	}
	printf("\n");
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
	if (size <= 100)
		lil_sort(&la, &lb);
	else
		radix(&la, &lb);
	quit_app(&la, &lb, 0); 
	return (0);
}
