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

void						run_chdir(t_shell *shell)
{
	if (chdir(get_home(shell->list)) != 0)
		ft_putendl("something wrong");
}

int							lsh_cd(t_shell *shell)
{
	t_bool					changed;

	changed = TRUE;
	if (shell->args[1] == NULL)
	{
		run_chdir(shell);
	}
	else
	{
		if (chdir(shell->args[1]) != 0)
		{
			if (ft_strcmp(shell->args[1], "~") == 0)
				run_chdir(shell);
			else if (ft_strcmp(shell->args[1], "-") == 0)
				run_chdir(shell);
			else
			{
				run_chdir(shell);
				changed = FALSE;
			}
		}
	}
	if (changed)
		change_pwds(shell);
	return (1);
}
