# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/02/21 19:12:23 by cefuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	main.c \
					parsing.c \
					error.c \
					lst_utils.c \
					lst_utils2.c \
					swap.c \
					push.c \
					rotate.c \
					reverse_rotate.c \
					sort.c \
					sort_utils.c \
					lil_sorts.c \
					rank.c
					
SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCLUDES_DIR	=	includes/

OBJS			=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
SRCS			=	$(addprefix $(SRCS_DIR),$(SRCS_LIST))
HEADER			=	$(INCLUDES_DIR)push_swap.h

CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -g 
RM				=	rm -rf
	
LIBFT			=	libft/libft.a 
LIBFT_DIR		=	libft/
LIBFT_LINK		=	ft


all			:	$(NAME)

$(NAME)		:	libft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -l$(LIBFT_LINK) -o $(NAME)

$(OBJS_DIR)%.o	:	%.c $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -c $< -o $@

libft	:
	$(MAKE) -C $(LIBFT_DIR)

clean		:
	$(RM) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean		:    clean
	$(RM) $(NAME) $(LIBFT)

re			:    fclean all

.PHONY		:	all clean fclean re libft