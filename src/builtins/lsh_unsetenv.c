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

t_env				*free_list_item(t_env *tmp)
{
	free(tmp->var);
	free (tmp->value);
	free (tmp);
	return (NULL);
}

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
			if (prev)
			{
				if (tmp->next)
				{
					prev->next = tmp->next;
					tmp = free_list_item(tmp);
				}
				else
				{
					tmp = free_list_item(tmp);
					prev->next = NULL;
				}
			}
			else
			{
				holder = tmp->next;
				tmp = free_list_item(tmp);
				shell->list = holder;
			}
		}
		prev = tmp;
		if (tmp && tmp->next)
			tmp = tmp->next;
	}
	return (shell->list);
}

int					lsh_unsetenv(t_shell *shell)
{
	t_env				*tmp;
	int				found;
	int				i;

	found = FALSE;
	i = 0;
	tmp = shell->list;
	if (shell->args[1])
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->var, shell->args[1]) == 0)
				found = TRUE;
			tmp = tmp->next;
		}
		if (found == TRUE)
			unset_existing_envv(shell);
	}
	return (1);
}