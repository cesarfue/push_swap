/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:12:49 by cesar             #+#    #+#             */
/*   Updated: 2024/02/19 19:43:17 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <../libft/includes/libft.h>
# include <../libft/includes/ft_printf.h>
# include "fcntl.h"

#include "stdio.h"

typedef struct s_o
{
	ssize_t	power;
	int		iter;
	int		size;
	int		max_iter;
} t_o;


typedef struct	s_lst
{
	struct s_lst	*next;
	int				val;
	int				lsd;
	int				is_first;
}	t_lst;

void	quit_app(t_lst **la, t_lst **lb, float err);
t_lst	*args_to_list(int argc, char **argv);
void	show(t_lst *la);
void	*tabjoin(char **str, int *size);
void	radix(t_lst **la, t_lst **lb);
size_t	intlen(int n);
t_lst	*init_lb(t_lst **la);
int		get_largest(t_lst *lst);
int		*init_array(void);
int		*set_array(t_lst *lst, int *count);
int		countsum(int *count);
int		check_dups(t_lst **la);
int		is_sorted(t_lst *lst);
void	set_is_first(t_lst **lst);
void	check_is_first(t_lst **lst, t_lst *first);
int		check_sum(t_lst **la, int sum);
void	lil_sorts(int argc, t_lst **la);
void	sort_three(t_lst **la);
int		ft_atoi(const char *str);


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