/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/07/08 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE 0
# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGLIGHT "\033[47m"
# define BGGRAY "\033[47m"

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"

typedef int					t_bool;

typedef struct				s_env
{
	char						*var;
	char						*value;
	char						**paths;
	struct s_env			*next;
	struct s_env			*prev;
}								t_env;

typedef struct				s_shell
{
	char						**built_ins;
	char						**envv;
	char						**args;
	t_env						*list;
}								t_shell;

typedef struct				s_lists
{
	t_env						*list;
	t_env						*tmp;
	t_env						*tmp2;
}								t_lists;

typedef struct				s_set
{
	char						**new_ev;
	int						i;
	size_t					l;
	t_env						*tmp;
	t_env						*tmp2;
}								t_set;

typedef struct				s_us
{
	t_env						*tmp;
	t_env						*prev;
	t_env						*holder;
}								t_us;

int							lsh_cd(t_shell *shell);
int							lsh_echo(char **args);
int							lsh_env(t_env *list);
int							lsh_exit(char **args);
int							lsh_help(char **args);
int							lsh_setenv(t_shell *shell);
int							lsh_unsetenv(t_shell *shell);
int							lsh_num_builtins(void);
int							lsh_execute(t_shell *shell);
int							lsh_launch(t_shell *shell);
int							builtin_check(t_shell *shell);
int							execute_path(t_shell shell);
void							mini_loop(t_shell *shell);
void							free_list(t_env *list);
void							free_table(char **array);
char							*command_path(char *path, char *command);
char							**setup_envv(t_env *list);
t_env							*setup_list(char **ev);

#endif
