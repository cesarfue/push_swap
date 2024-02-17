/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/16 15:28:08 by cesar            ###   ########.fr       */
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
	struct s_lst	*next;
	int				val;
	int				lsd;
	// int				index;
	int				is_first;
}	t_lst;

void	quit_app(t_lst **la, t_lst **lb, float err);
t_lst	*args_to_list(int argc, char **argv);
void	show(t_lst *la, t_lst *lb);
void	*tabjoin(char **str, int *size);
void	radix(t_lst **la, t_lst **lb);
size_t	intlen(int n);
t_lst	*init_lb(t_lst **la);
void	get_indexes(t_lst **lst);
int		get_largest(t_lst *lst);
int		*init_array(int *count);
int		is_sorted(t_lst *lst);
void	set_is_first(t_lst **lst);



/* List manipulation */

t_lst	*lstnew(int val);
void	lstadd_back(t_lst **lst, t_lst *new);
void	lstadd_front(t_lst **lst, t_lst *new);
void	lstfree(t_lst **lst);
t_lst	*lstlast(t_lst *lst);
t_lst	*lstblast(t_lst *lst);
int		lstsize(t_lst *lst);



/* Instructions */

void	sa(t_lst **la);
void	sb(t_lst **lb);
void	ss(t_lst **la, t_lst **lb);
void	swap_to(char list, t_lst **lst);
void	pa(t_lst **la, t_lst **lb);
void	pb(t_lst **lb, t_lst **la);
void	push_to(char list, t_lst **dest, t_lst **src);
void	ra(t_lst **la);
void	rb(t_lst **lb);
void	rr(t_lst **la, t_lst **lb);
void	rotate_to(char list, t_lst **lst);
void	rra(t_lst **la);
void	rrb(t_lst **lb);
void	rrr(t_lst **la, t_lst **lb);

#endif 