/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/08/24 15:06:52 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char					*clean_string(char *s)
{
	size_t				letters;
	char				*tmp;
	int					i;
	int					x;

	i = -1;
	letters = 0;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\v'
			&& s[i] != '\f' && s[i] != '\n' && s[i] != '"')
			letters++;
	if (letters == 0)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char) * letters + 1)))
		return (NULL);
	x = -1;
	i = -1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\r' && s[i] != '\v'
			&& s[i] != '\f' && s[i] != '\n' && s[i] != '"')
			tmp[++x] = s[i];
	tmp[++x] = '\0';
	ft_putstr("letters is: ");
	ft_putnbr(letters);
	ft_putchar('\n');
	return (tmp);
}
