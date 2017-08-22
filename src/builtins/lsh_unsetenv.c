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

t_env				*free_first_list_item(t_us *us)
{
	us->holder = us->tmp->next;
	free(us->tmp->var);
	free(us->tmp->value);
	free(us->tmp);
	us->tmp = NULL;
	return (us->holder);
}

void				free_mid_list_item(t_us *us)
{
	us->prev->next = us->tmp->next;
	free(us->tmp->var);
	free(us->tmp->value);
	free(us->tmp);
	us->tmp = NULL;
}

void				free_end_list_item(t_us *us)
{
	free(us->tmp->var);
	free(us->tmp->value);
	free(us->tmp);
	us->tmp = NULL;
	us->prev->next = NULL;
}

t_env					*unset_existing_envv(t_shell *shell)
{
	t_us				us;

	us.tmp = shell->list;
	us.prev = NULL;
	while (us.tmp)
	{
		if (ft_strcmp(us.tmp->var, shell->args[1]) == 0)
		{
			if (us.prev)
			{
				if (us.tmp->next)
					free_mid_list_item(&us);
				else
					free_end_list_item(&us);
			}
			else
				shell->list = free_first_list_item(&us);
		}
		us.prev = us.tmp;
		if (us.tmp && us.tmp->next)
			us.tmp = us.tmp->next;
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