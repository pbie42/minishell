/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      builtin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						builtin_check(t_shell shell)
{
	if (ft_strcmp(shell.args[0], "cd") == 0)
		return (lsh_cd(shell.args));
	else if (ft_strcmp(shell.args[0], "help") == 0)
		return (lsh_help(shell.args));
	else if (ft_strcmp(shell.args[0], "exit") == 0)
		return (lsh_exit(shell.args));
	else if (ft_strcmp(shell.args[0], "echo") == 0)
		return (lsh_echo(shell.args));
	else if (ft_strcmp(shell.args[0], "env") == 0)
		return (lsh_env(shell.envv));
	else
		return (0);
}