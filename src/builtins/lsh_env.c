/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/20 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						lsh_env(t_env *list)
{
	t_env					*tmp;

	tmp = list;
	while (tmp)
	{
		ft_putstr(tmp->var);
		ft_putchar('=');
		ft_putendl(tmp->value);
		tmp = tmp->next;
	}
	return (1);
}
