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

int						lsh_execute(char **args)
{
	int					i;

	i = 0;
	if(args == NULL || args[0] == NULL)
		return (1);
	if ((i = builtin_check(args)) == 0)
			return (i);
	else
		return lsh_launch(args);
}

int						lsh_launch(char **args)
{
	pid_t					pid;
	pid_t					wpid;
	int					status;

	pid = fork();
	if (pid == 0)
	{
		if(execvp(args[0], args) == -1)
			ft_exit("lsh");
		ft_exit("EXIT_FAILURE");
		
	}
	else if(pid < 0)
		ft_exit("lsh");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while(!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int						mini_exec(char *line, char **args)
{
	int					status;

	ft_putstr("$> ");
	ft_get_next_line(0, &line);
	args = ft_strsplit(line, ' ');
	status = lsh_execute(args);
	free(line);
	free(args);
	return (status);
}

void						mini_loop(void)
{
	char					**args;
	char					*line;
	int					status;

	line = NULL;
	args = NULL;
	status = mini_exec(line, args);
	while(status)
		status = mini_exec(line, args);
}