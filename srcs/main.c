/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:04:29 by cesar             #+#    #+#             */
/*   Updated: 2024/02/06 18:28:13 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_app	*app;

	if (!argv[1] || argc != 2)
		quit("Wrong arguments");
	app = ft_calloc(1, sizeof(t_app));
	if (!app)
		quit("Memory allocation failed");
	app->entry = argv[1];
	read_data(app);
	tab_to_list(app);
	quit_app(app, 0);
	return (0);
}