/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:30:27 by cesar             #+#    #+#             */
/*   Updated: 2024/02/17 16:20:41 by cesar            ###   ########.fr       */
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

void	quit_app(t_lst **la, t_lst **lb, float err)
{
	if (la)
		lstfree(la);
	if (lb)
		lstfree(lb);
	err_code(err);
}
