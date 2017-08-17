/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      lsh_help.c                                      :+:      :+:    :+:   */
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
	char					**agv;
	char						**builtin_str;

	i = -1;
	agv = args;
	builtin_str = ft_strsplit("cd help exit", ' ');
	ft_putendl("Paul Bie's Minishell");
	ft_putendl("Type program names and arguments, and hit enter.");
	ft_putendl("The following are built in:");
	while(builtin_str[++i] != NULL)
		ft_putendl(builtin_str[i]);
	ft_putendl("Use the man command for information on other programs.");
	return (1);
}