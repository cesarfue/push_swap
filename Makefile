# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cesar <cesar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 12:34:28 by cesar             #+#    #+#              #
#    Updated: 2024/02/14 22:29:17 by cesar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

SRCS_LIST		=	main.c \
					parsing.c \
					utils.c \
					error.c \
					lst_utils.c \
					swap.c \
					push.c \
					rotate.c \
					reverse_rotate.c \
					sort.c \
					sort_utils.c \
					
SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/
INCLUDES_DIR	=	includes/

OBJS			=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
SRCS			=	$(addprefix $(SRCS_DIR),$(SRCS_LIST))

CC				=	cc
FLAGS			=	-Wall -Wextra -g 
RM				=	rm -rf
	
LIBFT			=	libft/libft.a 
LIBFT_DIR		=	libft/
LIBFT_LINK		=	ft


all			:	$(NAME)

$(NAME)		:	libft $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -l$(LIBFT_LINK) -o $(NAME)


$(OBJS_DIR)%.o	:	%.c
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