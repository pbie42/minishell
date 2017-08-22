/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/18/09 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/18/09 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char						**get_path(t_env *list)
{
	t_env					*tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, "PATH") == 0)
			return (tmp->paths);
		tmp = tmp->next;
	}
	return (NULL);
}

int						check_for_path(char *givenpath)
{
	if (givenpath[0] == '/')
		return (1);
	else
		return (0);
}

char						*command_path(char *binpath, char *command)
{
	char					*bin;
	char					*path;
	size_t				l;

	if (check_for_path(command))
		return (command);
	else
	{
		bin = ft_strdup(binpath);
		l = ft_strlen(bin) + ft_strlen(command) + 1;
		path = NULL;
		if (!(path = (char*)malloc(sizeof(char) * l + 1)))
			return (NULL);
		path = ft_strcpy(path, bin);
		path = ft_strcat(path, "/");
		path = ft_strcat(path, command);
		free(bin);
	}
	return (path);
}

char						**setup_envv(t_env *list)
{
	t_set					set;

	set.i = 0;
	set.tmp = list;
	while (set.tmp)
	{
		set.tmp = set.tmp->next;
		set.i++;
	}
	set.new_ev = (char **)malloc(sizeof(char *) * (set.i + 1));
	set.i = 0;
	set.tmp2 = list;
	while (set.tmp2)
	{
		set.l = ft_strlen(set.tmp2->var) + ft_strlen(set.tmp2->value) + 1;
		if (!(set.new_ev[set.i] = (char*)malloc(sizeof(char) * set.l + 1)))
			return (NULL);
		set.new_ev[set.i] = ft_strcpy(set.new_ev[set.i], set.tmp2->var);
		set.new_ev[set.i] = ft_strcat(set.new_ev[set.i], "=");
		set.new_ev[set.i] = ft_strcat(set.new_ev[set.i], set.tmp2->value);
		set.tmp2 = set.tmp2->next;
		set.i++;
	}
	set.new_ev[set.i] = NULL;
	return (set.new_ev);
}

int						execute_path(t_shell shell)
{
	char					**paths;
	char					**envv;
	int					i;
	int					x;

	i = 0;
	envv = setup_envv(shell.list);
	paths = get_path(shell.list);
	while (paths[i] && (x = execve(command_path(paths[i], shell.args[0]), shell.args, envv) == -1))
		i++;
	free_table(envv);
	return (x);
}