/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env						*list_single(char *ev)
{
	char					**envv;
	t_env					*single;

	envv = ft_strsplit(ev, '=');
	if (!(single = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	single->next = NULL;
	single->prev = NULL;
	single->var = ft_strdup(envv[0]);
	single->value = ft_strdup(envv[1]);
	if (ft_strcmp(single->var, "PATH") == 0)
		single->paths = ft_strsplit(single->value, ':');
	else
		single->paths = NULL;
	free_table(envv);
	return (single);
}

t_env						*setup_list(char **ev)
{
	t_lists			l;
	int				i;

	i = 0;
	if (ev[i] != NULL)
		l.list = list_single(ev[i++]);
	else
		return (NULL);
	l.tmp = l.list;
	while (ev[i] != NULL)
	{
		l.tmp2 = list_single(ev[i]);
		if (l.tmp2 != NULL)
		{
			l.list->next = l.tmp2;
			l.list = l.list->next;
		}
		i++;
	}
	return (l.tmp);
}
