/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/12 11:28:50 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include "fcntl.h"

#include "stdio.h"

typedef struct	s_lst
{
	int				val;
	struct s_lst	*next;
}	t_lst;

void	quit_app(t_lst **la, t_lst **lb, float err);
t_lst	*args_to_list(int argc, char **argv);
void	show(t_lst **la, t_lst **lb);
void	*tabjoin(char **str, int *size);


/* List manipulation */
t_lst	*lstnew(int val);
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstadd_front(t_lst **lst, t_lst *new);
void	lstfree(t_lst **lst);
t_lst	*lstlast(t_lst *lst);


/* Instructions */
void	sa(t_lst **la);
void	sb(t_lst **lb);
void	ss(t_lst **la, t_lst **lb);
void	pa(t_lst **la, t_lst **lb);
void	pb(t_lst **lb, t_lst **la);
void	ra(t_lst **la);
void	rb(t_lst **lb);
void	rr(t_lst **la, t_lst **lb);
void	rra(t_lst **la);
void	rrb(t_lst **lb);
void	rrr(t_lst **la, t_lst **lb);

#endif 