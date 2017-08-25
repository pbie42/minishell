/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						spaces_check(char *s)
{
	int					i;

	ft_putendl("in spaces check");
	i = 0;
	while (s[i])
		if (s[i] != ' ' || s[i] != '\t' || s[i] != '\r' || s[i] != '\v'
		|| s[i] != '\f' || s[i] != '\n')
			return (1);
	ft_putendl("out of spaces while");
	return (0);
}
