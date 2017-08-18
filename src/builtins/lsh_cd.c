/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      lsh_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						lsh_cd(char **args)
{
	if (args[1] == NULL)
		ft_putendl("minishell: expected arguments to \"cd\"");
	else
	{
		if (chdir(args[1]) != 0)
			ft_exit("minishell");
		
	}
	return (1);
}