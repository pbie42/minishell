/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/17/09 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2017/17/09 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						lsh_execute(t_shell shell)
{
	int					i;

	if (shell.args == NULL || shell.args[0] == NULL)
		return (1);
	else if (ft_strcmp(shell.args[0], "exit") == 0)
		return (lsh_exit(shell.args));
	else if ((i = builtin_check(shell)) == 1)
		return (i);
	else
		return lsh_launch(shell);
}

int						lsh_launch(t_shell shell)
{
	pid_t					pid;
	pid_t					wpid;
	int					status;

	pid = fork();
	if (pid == 0)
	{
		if (execute_path(shell) == 1)
		{
			ft_putstr("minishell: command not found: ");
			ft_exit(shell.args[0]);
		}
		ft_exit("EXIT_FAILURE");
		
	}
	else if (pid < 0)
		ft_exit("lsh");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int						mini_exec(t_shell shell)
{
	int					status;
	char					*line;

	ft_putstr("$> ");
	ft_get_next_line(0, &line);
	shell.args = ft_strsplit(line, ' ');
	status = lsh_execute(shell);
	free(line);
	free_table(shell.args);
	return (status);
}

void						mini_loop(t_shell shell)
{
	int					status;

	status = mini_exec(shell);
	while (status)
		status = mini_exec(shell);
}