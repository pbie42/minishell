/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/08/24 15:20:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						main(int ac, char **av, char **ev)
{
	int					argc;
	char				**argv;
	t_shell				shell;

	argc = ac;
	argv = av;
	shell.list = setup_list(ev);
	mini_loop(&shell);
	free(shell.args);
	free_list(shell.list);
	return (0);
}
