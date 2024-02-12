/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .archive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:50:44 by cesar             #+#    #+#             */
/*   Updated: 2024/02/09 14:50:54 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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