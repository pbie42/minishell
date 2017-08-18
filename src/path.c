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

char						*command_path(char *binpath, char *command)
{
	char					*bin;
	char					*path;
	size_t				l;

	bin = ft_strdup(binpath);
	l = ft_strlen(bin) + ft_strlen(command) + 1;
	path = NULL;
	if (!(path = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	path = ft_strcpy(path, bin);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, command);
	free(bin);
	return (path);
}

int						execute_path(t_shell shell)
{
	char					**paths;
	int					i;
	int					x;

	i = 0;
	paths = get_path(shell.list);
	while (paths[i] && (x = execve(command_path(paths[i], shell.args[0]), shell.args, shell.envv) == -1))
		i++;
	return (x);
}