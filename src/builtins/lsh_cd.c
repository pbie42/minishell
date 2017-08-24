/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/08/24 15:15:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void						run_chdir_home(t_shell *shell)
{
	if (chdir(get_home(shell->list)) != 0)
		ft_putendl("something wrong");
}

void						run_chdir_old(t_shell *shell)
{
	if (chdir(get_old_pwd(shell->list)) != 0)
		ft_putendl("something wrong");
}

int							lsh_cd(t_shell *shell)
{
	t_bool					changed;

	changed = TRUE;
	if (shell->args[1] == NULL)
		run_chdir_home(shell);
	else
	{
		if (chdir(shell->args[1]) != 0)
		{
			if (ft_strcmp(shell->args[1], "~") == 0)
				run_chdir_home(shell);
			else if (ft_strcmp(shell->args[1], "-") == 0)
				run_chdir_old(shell);
			else
			{
				ft_putstr("cd: no such file or directory: ");
				ft_putendl(shell->args[1]);
				changed = FALSE;
			}
		}
	}
	if (changed)
		change_pwds(shell);
	return (1);
}
