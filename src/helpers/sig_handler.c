/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/08 13:28:10 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void						prompt(void)
{
	ft_putstr(GREEN);
	ft_putchar('\n');
	ft_putstr("$> ");
	ft_putstr(STOP);
}

void						sig_handler(int signo)
{
	if (signo == SIGKILL)
		prompt();
	else if (signo == SIGSTOP)
		prompt();
	else if (signo == SIGINT)
		prompt();
	else
		prompt();
}
