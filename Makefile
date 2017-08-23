# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 11:55:43 by pbie              #+#    #+#              #
#    Updated: 2016/05/19 14:54:01 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -g -Wall -Werror -Wextra -I includes

SRC = src/main.c \
		src/builtins/builtin_check.c \
		src/builtins/lsh_cd.c \
		src/builtins/lsh_echo.c \
		src/builtins/lsh_env.c \
		src/builtins/lsh_exit.c \
		src/builtins/lsh_help.c \
		src/builtins/lsh_setenv.c \
		src/builtins/lsh_unsetenv.c \
		src/execution/execution.c \
		src/execution/path.c \
		src/free/free_existing_envv.c \
		src/free/free_list.c \
		src/free/free_table.c \
		src/helpers/clean_string.c \
		src/helpers/spaces_check.c \
		src/list/setup_list.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libft.h libft/libft.a
	@echo "$(NAME) created"

clean :
	make -C libft clean
	rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libft.a
	@echo "$(NAME) deleted"

re : fclean all

.PHONY: all clean fclean re
