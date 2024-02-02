/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/02 10:05:28 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_app	*app;

	if (!argv[1] || argc != 2)
		quit("Wrong arguments");
	app = malloc_er(sizeof(t_app));
	app->entry = argv[1];
	read_data(app); 
	int i = 0;
	while (i < app->size)
		ft_printf("%d\n", app->data[i++]);
	free(app->data);
	free(app);
	return (0);
}