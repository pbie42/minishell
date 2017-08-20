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
	char					**new_ev;
	int					i;
	size_t				l;
	t_env					*tmp;
	t_env					*tmp2;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	new_ev = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp2 = list;
	while (tmp2)
	{
		l = ft_strlen(tmp2->var) + ft_strlen(tmp2->value) + 1;
		if (!(new_ev[i] = (char*)malloc(sizeof(char) * l + 1)))
			return (NULL);
		new_ev[i] = ft_strcpy(new_ev[i], tmp2->var);
		new_ev[i] = ft_strcat(new_ev[i], "=");
		new_ev[i] = ft_strcat(new_ev[i], tmp2->value);
		tmp2 = tmp2->next;
		i++;
	}
	new_ev[i] = NULL;
	return (new_ev);
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