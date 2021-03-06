/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/08 13:27:34 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int						lsh_execute(t_shell *shell)
{
	int					i;

	if (shell->args == NULL || shell->args[0] == NULL)
		return (1);
	else if (ft_strcmp(shell->args[0], "exit") == 0)
		return (lsh_exit(shell->args));
	else if ((i = builtin_check(shell)) == 1)
		return (i);
	else
		return (lsh_launch(shell));
}

int						lsh_launch(t_shell *shell)
{
	pid_t				pid;
	pid_t				wpid;
	int					status;

	pid = fork();
	if (pid == 0)
	{
		if (execute_path(*shell) == 1)
		{
			ft_putstr("minishell: command not found: ");
			ft_putendl(shell->args[0]);
			return (0);
		}
	}
	else if (pid < 0)
		ft_exit("lsh");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int						semi_execute(t_shell *shell, char *line)
{
	t_s					s;

	if (non_semi_check(line))
	{
		free(line);
		return (1);
	}
	s.semi_args = ft_strsplit(line, ';');
	free(line);
	s.i = -1;
	s.semi_shell.list = shell->list;
	while (s.semi_args[++s.i])
	{
		s.semi_shell.args = ft_strsplit(s.semi_args[s.i], ' ');
		if (s.semi_shell.args)
			args_cleanup(&s.semi_shell);
		s.status = lsh_execute(&s.semi_shell);
		free_table(s.semi_shell.args);
		if (s.status == 0)
			return (s.status);
	}
	free_table(s.semi_args);
	return (1);
}

int						mini_exec(t_shell *shell)
{
	int					status;
	char				*line;

	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putendl("problem");
	else
		prompt_main();
	ft_get_next_line(0, &line);
	clear_white(line);
	if (semi_check(line))
		return (semi_execute(shell, line));
	if (!alpha_check(line))
	{
		free(line);
		return (1);
	}
	if (line)
		shell->args = ft_strsplit(line, ' ');
	free(line);
	if (shell->args)
		args_cleanup(shell);
	status = lsh_execute(shell);
	free_table(shell->args);
	return (status);
}

void					mini_loop(t_shell *shell)
{
	int					status;

	status = mini_exec(shell);
	while (status)
		status = mini_exec(shell);
}
