/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_unsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2016/05/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env					*unset_existing_envv(t_shell *shell)
{
	t_env				*tmp;
	t_env				*prev;
	t_env				*holder;

	tmp = shell->list;
	prev = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, shell->args[1]) == 0)
		{
			ft_putendl("gettin here");
			if (prev)
			{
				ft_putendl("prev exists");
				if (tmp->next)
				{
					ft_putendl("tmp->next exists");
					prev->next = tmp->next;
					free(tmp->var);
					free (tmp->value);
					free (tmp);
					tmp = NULL;
				}
				else
				{
					ft_putendl("tmp->next does not exist");
					ft_putendl(tmp->var);
					ft_putendl(tmp->value);
					free(tmp->var);
					free (tmp->value);
					free (tmp);
					tmp = NULL;
					prev->next = NULL;
				}
			}
			else
			{
				holder = tmp->next;
				free(tmp->var);
				free(tmp->value);
				free(tmp);
				shell->list = holder;
				tmp = NULL;
			}
		}
		ft_putendl("putting prev to tmp");
		prev = tmp;
		ft_putendl("put prev to tmp");
		if (tmp && tmp->next)
		{
			ft_putendl("tmp->next does exist again");
			tmp = tmp->next;
		}
		ft_putendl("past last if");
	}
	return (shell->list);
}

int					lsh_unsetenv(t_shell shell)
{
	t_env				*tmp;
	int				found;
	int				i;

	found = FALSE;
	i = 0;
	tmp = shell.list;
	if (shell.args[1])
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->var, shell.args[1]) == 0)
				found = TRUE;
			tmp = tmp->next;
		}
		if (found == TRUE)
			unset_existing_envv(&shell);
	}
	return (1);
}