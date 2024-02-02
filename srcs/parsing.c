/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/02 10:23:06 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tabjoin(char **str, int **data, int *size)
{
	int			i;

	i = 0;
	while (str[i])
	{
		*data = ft_realloc(*data, *size * sizeof(int), (*size + 1) * sizeof(int));
		(*data)[*size] = ft_atoi(str[i]);
		free(str[i++]);
		(*size)++;
	}
	free(str);
}

void	read_data(t_app *app)
{
	app->fd = open(app->entry, O_RDONLY);
	app->size = 0;
	app->data = NULL;
	if (app->fd == -1)
		tabjoin(ft_split(app->entry, ' '), &app->data, &app->size);
	else 
	{
		app->entry = get_next_line(app->fd);
		while (app->entry != NULL)
		{
			tabjoin(ft_split(app->entry, ' '), &app->data, &app->size);
			free(app->entry);
			app->entry = get_next_line(app->fd);
		}
		close(app->fd);
	}
}
