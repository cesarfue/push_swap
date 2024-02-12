/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:30:27 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 20:46:35 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	err_code(float err)
{
	if (err == 0)
		exit(0);
	else if (err == 1)
		quit("Error\n");
}

void	quit_app(t_lst **la, float err)
{
	lstfree(la);
	err_code(err);
}
