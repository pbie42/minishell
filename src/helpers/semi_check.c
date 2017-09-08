/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/08 13:23:25 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						semi_check(char *s)
{
	int					i;

	i = -1;
	while (s[++i])
		if (s[i] == ';')
			return (1);
	return (0);
}

int						non_semi_check(char *s)
{
	int					i;

	i = -1;
	while (s[++i])
		if (s[i] != ';' && i > 0)
			return (0);
	return (1);
}