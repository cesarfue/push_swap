/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/01 14:36:10 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	atoiverse(char **str, int **data, int *size)
{
	int			i;

	i = 0;
	while (str[i])
	{
		*data = ft_realloc(*data, *size * sizeof(int), (*size + 1) * sizeof(int));
		if (!*data)
			quit("realloc failed");
		(*data)[*size] = ft_atoi(str[i]);
		free(str[i++]);
		(*size)++;
	}
	free(str);
	printf("size is %d\n", *size); 
}

void	read_data(t_app *app)
{
	if (app->file)
	{
		app->fd = open(app->file, O_RDONLY);
		if (app->fd == -1)
			quit("Invalid fd");
	}
	else
		app->fd = STDIN_FILENO;
	app->size = 0;
	app->data = NULL;
	app->line = get_next_line(app->fd);
	while (app->line != NULL)
	{
		app->splat_line = ft_split(app->line, ' ');
		atoiverse(app->splat_line, &app->data, &app->size);
		free(app->line);
		app->line = get_next_line(app->fd);
	}
	close(app->fd);
}
