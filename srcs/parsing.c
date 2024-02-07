/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/06 18:39:28 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*tabjoin(char **str, int **data, int *size)
{
	int			i;

	i = 0;
	while (str[i])
	{
		*data = ft_realloc(*data, *size * sizeof(int), (*size + 1) * sizeof(int));
		if (!*data)
			return (freetab((void **) str, *size), NULL);
		(*data)[*size] = ft_atoi(str[i]);
		free(str[i++]);
		(*size)++;
	}
	free(str);
	return (data);
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
		app->entry = get_next_line(app->fd, &app->rope);
		while (app->entry != NULL)
		{
			tabjoin(ft_split(app->entry, ' '), &app->data, &app->size);
			if (!app->data)
				return (free(app->rope), free(app->entry), quit_app(app, 1));
			free(app->entry);
			app->entry = get_next_line(app->fd, &app->rope);
		}
		free(app->entry);
		close(app->fd);
	}
}

t_list	*tab_to_list(t_app *app)
{
	t_list	*start;
	t_list	*new;
	int		i;
	int		*data_copy;

	start = NULL;
	i = 0;
	while (i < app->size)
	{
		data_copy = malloc(sizeof(int));
		data_copy = arr[i]
		new = ft_lstnew(&app->data[i]);
		if (new == NULL)
			return (ft_lstclear(&start, free), NULL);
		ft_lstadd_back(&start, new);
		i++;
	}
	return (start);
}
