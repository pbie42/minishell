/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				free_list(t_env *list)
{
	t_env			*curr;
	
	while ((curr = list) != NULL)
	{
		list = list->next;
		ft_putendl(curr->var);
		if (ft_strcmp(curr->var, "PATH") == 0)
			free_table(curr->paths);
		free(curr->var);
		free(curr->value);
		free (curr);
	}
}