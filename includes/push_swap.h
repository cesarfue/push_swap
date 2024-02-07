/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/06 18:14:26 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include "fcntl.h"

typedef struct s_app
{
	char	*entry;
	int		*data;
	int		fd;
	int		size;
	char	*rope;
}	t_app;

void	read_data(t_app *app);
void	*calloc_er(size_t nmemb, size_t size, t_app *app, float err);
void	quit_app(t_app *app, float err);
void	*calloc_er(size_t nmemb, size_t size, t_app *app, float err);

#endif 