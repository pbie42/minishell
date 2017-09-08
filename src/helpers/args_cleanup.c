/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/08 15:02:31 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					args_cleanup(t_shell *shell)
{
	char				*tmp;
	int					i;

	i = -1;
	while (shell->args[++i])
	{
		tmp = clean_string(shell->args[i]);
		free(shell->args[i]);
		shell->args[i] = ft_strdup(tmp);
		free(tmp);
	}
}
