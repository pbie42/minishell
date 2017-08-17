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

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"

typedef int					t_bool;

typedef struct				s_shell
{
	char						**built_ins;
	char						**envv;
}								t_shell;

int							lsh_cd(char **args);
int							lsh_help(char **args);
int							lsh_exit(char **args);
int							lsh_num_builtins(void);
int							lsh_execute(char **args);
int							lsh_launch(char **args);
int							builtin_check(char **args);
void							mini_loop(void);

#endif
