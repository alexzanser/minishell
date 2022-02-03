# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eveiled <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:45:23 by eveiled           #+#    #+#              #
#   Updated: 2021/12/19 15:00:54 by eveiled          ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = minishell
#
SOURSE = build_in/*.c ft_exec_files/*.c gnl/*.c \
		parser/*.c
#
CFLAGS		= -Wall -Werror -Wextra -I $(HEADER)
HEADER	= minishell.h
OBJ = $(SOURSE:%.c=%.o)
CC = gcc
LIBFTDIR = ./libft
READLINE = -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include -lreadline
#
.PHONY : all clean fclean re re_libft
#
all : $(NAME)
#
$(NAME) :  $(SOURSE) $(HEADER)
	@make -C $(LIBFTDIR)
	$(CC) -L./libft -lft $(CFLAGS) $(READLINE) $(SOURSE) -o $(NAME)
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	@rm -f $(OBJ)
	@make clean -C $(LIBFTDIR)
#
fclean : clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
#
re_libft :
	@make re -C $(LIBFTDIR)
#
re : fclean re_libft all



