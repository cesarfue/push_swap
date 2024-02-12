/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:19:52 by cesar             #+#    #+#             */
/*   Updated: 2024/02/09 15:42:17 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_tab(void **tab, int size)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < size)
	{
		if (tab[i])
			free(tab[i++]);
	}
	free(tab);
}

void	*tabjoin(char **str, int *size)
{
	int		*data;

	*size = 0;
	data = NULL;
	while (str[*size])
	{
		data = ft_realloc(&data, *size * sizeof(int), ((*size) + 1) * sizeof(int));
		if (!data)
			return (freetab((void **)str, *size), NULL);
		data[*size] = ft_atoi(str[*size]);
		free(str[(*size)++]);
	}
	free(str);
	return (data);
}
