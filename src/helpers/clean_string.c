/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char						*clean_string(char *s)
{
	size_t				letters;
	char					*tmp;
	int					i;
	int					x;

	i = -1;
	letters = 0;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\v'
			&& s[i] != '\f' && s[i] != '\n')
			letters++;
	if (!(tmp = (char*)malloc(sizeof(char) * letters + 1)))
		return (NULL);
	x = -1;
	i = -1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\v'
			&& s[i] != '\f' && s[i] != '\n')
			tmp[++x] = s[i];
	tmp[++x] = '\0';
	return (tmp);
}