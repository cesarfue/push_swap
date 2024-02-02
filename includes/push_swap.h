/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/02 10:23:32 by cesar            ###   ########.fr       */
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
}	t_app;

void	read_data(t_app *app);
void	free_tab(void **tab, int size);


#endif 