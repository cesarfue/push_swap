/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:30:27 by cesar             #+#    #+#             */
/*   Updated: 2024/02/06 18:04:00 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*calloc_er(size_t nmemb, size_t size, t_app *app, float err)
{
	void		*ret;

	ret = ft_calloc(nmemb, size);
	if (ret == NULL)
		quit_app(app, err);
	return (ret);
}

void	err_code(float err)
{
	if (err == 0)
		exit(0);
	else if (err == 1)
		quit("1");
}

void	quit_app(t_app * app, float err)
{
	free(app->data);
	free(app);
	err_code(err);
}