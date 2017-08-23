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

char						*get_old_pwd(t_env *list)
{
	t_env					*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, "OLDPWD") == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void						change_pwds(t_shell *shell)
{
	char					cwd[1024];
	char					*pwd;
	t_env					*tmp;
	t_env					*tmp2;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		ft_putendl("getcwd problem");
	tmp = shell->list;
	tmp2 = shell->list;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, "PWD") == 0)
			pwd = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		if (ft_strcmp(tmp2->var, "PWD") == 0)
			free_pwd(tmp2, cwd);
		if (ft_strcmp(tmp2->var, "OLDPWD") == 0)
			free_old_pwd(tmp2, pwd);
		tmp2 = tmp2->next;
	}
}

int						lsh_cd(t_shell *shell)
{
	t_bool				changed;

	changed = TRUE;
	if (shell->args[1] == NULL)
	{
		if (chdir(get_home(shell->list)) != 0)
			ft_putendl("something wrong");
	}
	else
	{
		if (chdir(shell->args[1]) != 0)
		{
			if (ft_strcmp(shell->args[1], "~") == 0)
			{
				if (chdir(get_home(shell->list)) != 0)
					ft_putendl("something wrong");
			}
			else if (ft_strcmp(shell->args[1], "-") == 0)
			{
				if (chdir(get_old_pwd(shell->list)) != 0)
					ft_putendl("something wrong");
			}
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