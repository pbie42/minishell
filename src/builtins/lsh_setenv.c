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

void					set_existing_envv(t_shell shell, char **env)
{
	char				*new_envv;
	size_t			l;

	l = ft_strlen(shell.args[1]) + ft_strlen(shell.args[2]) + 1;
	if (!(new_envv = (char*)malloc(sizeof(char) * l + 1)))
		ft_exit("Malloc Error");
	new_envv = ft_strcpy(new_envv, shell.args[1]);
	new_envv = ft_strcat(new_envv, "=");
	new_envv = ft_strcat(new_envv, shell.args[2]);
	*env = new_envv;
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
			set_existing_envv(shell, &shell.envv[i])
	}
}