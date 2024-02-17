/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:55:14 by cesar             #+#    #+#             */
/*   Updated: 2024/02/17 15:27:08 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*init_array(void)
{
	int	*count;
	
	count = malloc(10 * sizeof(int));
	if (count == NULL)
		return (NULL);
	return (count);
}

int	*set_array(t_lst *lst, int *count)
{
	int	i;

	i = 0;
	while (i < 10)
		count[i++] = 0;
	while (lst)
	{
		count[lst->lsd]++;
		lst = lst->next;
	}
	return (count);
}

int	countsum(int *count)
{
	int	i;
	int	sum;

	i = 1;
	sum = 0;
	while (i < 10)
		sum += count[i++];
	return (sum);
}