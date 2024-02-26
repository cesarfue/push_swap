/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:16:37 by cefuente          #+#    #+#             */
/*   Updated: 2024/02/26 16:03:54 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	atosi(const char *str, int *ret)
{
	size_t	i;
	int		x;
	long	nb;

	i = 0;
	x = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb = nb * 10 + (str[i++] - '0');
	}
	nb *= x;
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (*ret = (int)nb, 1);
}

void	freetab_ukwn(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

t_lst	*str_to_lst(char *str, int *size)
{
	t_lst		*la;
	t_lst		*new;
	int			val;
	char		**tab;
	int			i;

	la = NULL;
	i = 0;
	tab = ft_split(str, ' ');
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		if (atosi(tab[i], &val) == 0)
			return (freetab_ukwn((void **)tab), lstfree(&la), NULL);
		new = lstnew((int)val);
		if (new == NULL)
			return (freetab_ukwn((void **)tab), lstfree(&la), NULL);
		lstadd_back(&la, new);
		i++;
	}
	freetab((void **)tab, i);
	*size = i;
	return (la);
}

t_lst	*args_to_list(int argc, char **argv, int *size)
{
	t_lst		*la;
	t_lst		*new;
	int			val;
	int			i;

	la = NULL;
	i = 1;
	while (i < argc)
	{
		if (!atosi(argv[i], &val))
			return (lstfree(&la), NULL);
		new = lstnew((int)val);
		if (new == NULL)
			return (lstfree(&la), NULL);
		lstadd_back(&la, new);
		i++;
	}
	*size = i - 1;
	return (la);
}
