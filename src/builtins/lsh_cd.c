/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      lsh_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char						*get_home(t_env *list)
{
	t_env					*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, "HOME") == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int						lsh_cd(t_shell shell)
{
	if (shell.args[1] == NULL)
	{
		// if (shell.args[0][0] == '.' || shell.args[0][0] == '/')
		// {
		// 	ft_putendl("gettin in here");
		// 	if (chdir(shell.args[0]) != 0)
		// 		ft_exit("minishell");
		// 	return (-1);
		// }
		if (chdir(get_home(shell.list)) != 0)
			ft_putendl("something wrong");
	}
	else
	{
		if (chdir(shell.args[1]) != 0)
		{
			if (ft_strcmp(shell.args[1], "~") == 0)
			{
				if (chdir(get_home(shell.list)) != 0)
					ft_putendl("something wrong");
			}
			else
			{
				ft_putstr("cd: no such file or directory: ");
				ft_putendl(shell.args[1]);
			}
		}
	}
	return (1);
}