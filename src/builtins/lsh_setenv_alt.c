/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_setenv_alt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/08/24 17:20:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env					*new_envv_alt(char **args)
{
	t_env				*tmp;

	if (!(tmp = (t_env *)malloc(sizeof(t_env))))
		ft_putendl("malloc errror in set_new_envv");
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->var = ft_strdup(args[0]);
	tmp->value = ft_strdup(args[1]);
	return (tmp);
}

void					set_existing_envv_alt(t_shell *shell, char **args)
{
	size_t				l;
	t_env				*tmp;

	tmp = shell->list;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, args[0]) == 0)
		{
			ft_strdel(&tmp->value);
			l = ft_strlen(args[1]);
			if (!(tmp->value = (char*)malloc(sizeof(char) * l + 1)))
				ft_exit("Malloc Error");
			tmp->value = ft_strdup(args[1]);
			return ;
		}
		tmp = tmp->next;
	}
}

void					set_with_alt_command(t_shell *shell)
{
	char				**table;
	t_env				*tmp;
	t_bool				found;

	table = ft_strsplit(shell->args[1], '=');
	tmp = shell->list;
	found = FALSE;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, table[0]) == 0)
			found = TRUE;
		tmp = tmp->next;
	}
	if (found == TRUE)
		set_existing_envv_alt(shell, table);
	else
		set_new_envv(&shell->list, table);
	free_table(table);
}
