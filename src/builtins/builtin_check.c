/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      builtin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						builtin_check(char **args)
{
	if (ft_strcmp(args[0], "cd") == 0)
		return (lsh_cd(args));
	else if (ft_strcmp(args[0], "help") == 0)
		return (lsh_help(args));
	else if (ft_strcmp(args[0], "exit") == 0)
		return (lsh_exit(args));
	else
		return (1);
}