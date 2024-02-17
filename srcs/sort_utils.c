/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:27:21 by cesar             #+#    #+#             */
/*   Updated: 2024/02/15 16:20:46 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_lst *lst)
{
	while (lst->next)
	{
		if (lst->val > lst->next->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	get_indexes(t_lst **lst)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (*lst)
	{
		(*lst)->index = i++;
		*lst = (*lst)->next;
	}
	*lst = tmp;
}

int	get_largest(t_lst *lst)
{
	int ret;

	ret = INT_MIN;
	while (lst)
	{
		if (lst->val > ret)
			ret = lst->val;
		lst = lst->next;
	}
	return (ret); 
}

int	*init_array(int *count)
{
	int	i;
	
	count = malloc(10 * sizeof(int));
	if (count == NULL)
		return (NULL);
	i = 0;
	while (i < 10)
		count[i++] = 0;
	return (count);
}
