/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/08/17 17:38:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void						print_list(t_env *list)
{
	while (list)
	{
		ft_putendl(list->var);
		ft_putstr("\t");
		ft_putendl(list->value);
		list = list->next;
	}
}

int						main(int ac, char **av, char **ev)
{
	int					argc;
	char					**argv;
	t_shell				shell;

	argc = ac;
	argv = av;
	shell.envv = ev;
	shell.list = setup_list(ev);
	print_list(shell.list);
	mini_loop(shell);
	return (0);
}
