/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:30:27 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 09:08:30 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	err_code(float err)
{
	if (err == 0)
		exit(0);
	else if (err == 1)
		quit("Invalid arguments");
	else if (err == 2)
		quit("Memory allocation failed (2; linked list)");
}

void	quit_app(t_lst **la, t_lst **lb, float err)
{
	if (err >= 2 || err == 0)
	{
		lstfree(la);
		lstfree(lb);
	}
	err_code(err);
}