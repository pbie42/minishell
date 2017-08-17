/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/17/09 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/17/09 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						lsh_help(char **args)
{
	int					i;
	char				**agv;

	i = 0;
	agv = args;
	ft_putendl("Paul Bie's LSH");
	ft_putendl("Type program names and arguments, and hit enter.");
	ft_putendl("The following are built in:");
	while (i < lsh_num_builtins())
	{
		ft_putendl(builtin_str[i]);
		i++;
	}
	ft_putendl("Use the man command for information on other programs.");
	return (1);
}