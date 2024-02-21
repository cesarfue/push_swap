/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/21 18:52:03 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include "fcntl.h"

typedef struct	s_lst
{
	struct s_lst	*next;
	int				val;
	int				is_theone;
	int				rank;
}	t_lst;

void	quit_app(t_lst **la, t_lst **lb, float err);
t_lst	*args_to_list(int argc, char **argv, int *size);
t_lst	*str_to_lst(char *str, int *size);
void	radix(t_lst **la, t_lst **lb);
int		check_dups(t_lst **la);
int		is_sorted(t_lst *lst);

/* Tiny sort*/

int		get_lowest(t_lst *lst);
void	lil_sort(t_lst **la, t_lst **lb);
void	mark_the_one(t_lst **lst);
void	go_to_the_one(char list, t_lst **lst, int size);
void	sort_three(t_lst **la);

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
void	reverse_rotate_to(char list, t_lst **lst);

#endif 