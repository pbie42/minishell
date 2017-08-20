/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/20 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					set_existing_envv(t_shell shell, int i)
{
	size_t			l;

	ft_strdel(&shell.envv[i]);
	l = ft_strlen(shell.args[1]) + ft_strlen(shell.args[2]) + 1;
	if (!(shell.envv[i] = (char*)malloc(sizeof(char) * l + 1)))
		ft_exit("Malloc Error");
	shell.envv[i] = ft_strcpy(shell.envv[i], shell.args[1]);
	shell.envv[i] = ft_strcat(shell.envv[i], "=");
	shell.envv[i] = ft_strcat(shell.envv[i], shell.args[2]);
}

int					lsh_setenv(t_shell shell)
{
	t_env				*tmp;
	int				found;
	int				i;

	found = FALSE;
	i = 0;
	tmp = shell.list;
	if (shell.args[2])
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->var, shell.args[1]) == 0)
				found = TRUE;
			if (found != TRUE)
				i++;
			tmp = tmp->next;
		}
		if (found == TRUE)
			set_existing_envv(shell, i);
		// else
		// 	set_new_envv(shell);
	}
	return (1);
}