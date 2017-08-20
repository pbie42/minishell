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

// void						print_list(t_env *list)
// {
// 	while (list)
// 	{
// 		ft_putendl(list->var);
// 		ft_putstr("\t");
// 		ft_putendl(list->value);
// 		list = list->next;
// 	}
// }

// void						print_table(char **table)
// {
// 	int					i;

// 	i = -1;
// 	while (table[++i])
// 		ft_putendl(table[i]);
// 	ft_putendl("\n");
// }

char						**setup_envv(char **ev)
{
	char					**new_ev;
	int					i;

	i = 0;
	while (ev[i])
		i++;
	new_ev = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (ev[++i])
		new_ev[i] = strdup(ev[i]);
	new_ev[i] = NULL;
	return (new_ev);
}

int						main(int ac, char **av, char **ev)
{
	int					argc;
	char					**argv;
	t_shell				shell;

	argc = ac;
	argv = av;
	shell.envv = setup_envv(ev);
	shell.list = setup_list(ev);
	mini_loop(shell);
	free(shell.args);
	free_list(shell.list);
	free_table(shell.envv);
	return (0);
}
