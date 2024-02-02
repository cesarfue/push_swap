/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/02 08:38:36 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_app	*app;

	if (!argv[1] || argc != 2)
		quit("Wrong arguments");
	app = malloc(sizeof(t_app));
	app->file = argv[1];
	read_data(app); 
	int i = 0;
	while (i < app->size)
		ft_printf("%d\n", app->data[i++]);
	free_tab_in((void **)app->data, app->size);
	// free(app);
	return (0);
}