/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/20 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					print_list(t_env *list)
{
	t_env				*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putendl(tmp->var);
		ft_putstr("\t");
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
}

int						builtin_check(t_shell *shell)
{
	if (ft_strcmp(shell->args[0], "cd") == 0)
		return (lsh_cd(shell));
	else if (ft_strcmp(shell->args[0], "help") == 0)
		return (lsh_help(shell->args));
	else if (ft_strcmp(shell->args[0], "echo") == 0)
		return (lsh_echo(shell->args));
	else if (ft_strcmp(shell->args[0], "env") == 0)
		return (lsh_env(shell->list));
	else if (ft_strcmp(shell->args[0], "setenv") == 0)
		return (lsh_setenv(shell));
	else if (ft_strcmp(shell->args[0], "unsetenv") == 0)
		return (lsh_unsetenv(shell));
	else
		return (0);
}
