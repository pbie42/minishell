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

void					set_existing_envv(t_shell *shell)
{
	size_t			l;
	t_env				*tmp;

	tmp = shell->list;
	while(tmp)
	{
		if (ft_strcmp(tmp->var, shell->args[1]) == 0)
		{
			ft_strdel(&tmp->value);
			l = ft_strlen(shell->args[2]);
			if (!(tmp->value = (char*)malloc(sizeof(char) * l + 1)))
				ft_exit("Malloc Error");
			tmp->value = ft_strcat(tmp->value, shell->args[2]);
			return ;
		}
		tmp = tmp->next;
	}
}

t_env					*new_envv(char **args)
{
	t_env				*tmp;

	if (!(tmp = (t_env *)malloc(sizeof(t_env))))
		ft_putendl("malloc errror in set_new_envv");
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->var = ft_strdup(args[1]);
	tmp->value = ft_strdup(args[2]);
	return (tmp);
}

void					set_new_envv(t_env **list, char **args)
{
	t_env				*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_envv(args);
}

int					lsh_setenv(t_shell *shell)
{
	t_env				*tmp;
	int				found;
	int				i;

	found = FALSE;
	i = 0;
	tmp = shell->list;
	if (shell->args[2])
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->var, shell->args[1]) == 0)
				found = TRUE;
			tmp = tmp->next;
		}
		if (found == TRUE)
			set_existing_envv(shell);
		else
			set_new_envv(&shell->list, shell->args);
	}
	return (1);
}