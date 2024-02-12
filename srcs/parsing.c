/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/12 09:25:31 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lst	*args_to_list(int argc, char **argv)
{
	t_lst		*la;
	t_lst		*new;
	long int	val;
	int			i;

	la = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (NULL);
		new = lstnew(val);
		if (new == NULL)
			return (NULL);
		lstadd_back(&la, new);
		i++;	
	}
	return (la);
}

// t_lst	*char_to_list(int argc, char **argv)
// {
// 	int			i;
// 	int			size;
// 	int			*data;
// 	t_lst		*la;
// 	t_lst		*new;
// 	long int	val;

// 	size = 0;
// 	i = 0;
// 	data = (int *)tabjoin(ft_split(argv[1], ' '), &size);
// 	while (i < size)
// 	{
// 		val = data[i];
// 		if (val > INT_MAX || val < INT_MIN)
// 			return (NULL);
// 		new = lstnew(val);
// 		if (new == NULL)
// 			return (NULL);
// 		lstadd_back(&la, new);
// 		i++;	
// 	}
// 	return (la); 
// }
