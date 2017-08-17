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

int						lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int						lsh_launch(char **args)
{
	pid_t				pid;
	pid_t				wpid;
	int					status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			ft_exit("lsh");
		ft_exit("EXIT_FAILURE");
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

int						lsh_execute(char **args)
{
	int					i;

	i = 0;
	if (args[0] == NULL)
		return (1);
	while (i < lsh_num_builtins())
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
		i++;
	}
	return (lsh_launch(args));
}

void					mini_loop(void)
{
	char				**args;
	char				*line;
	int					status;

	line = NULL;
	ft_putstr("$> ");
	ft_get_next_line(0, &line);
	args = ft_strsplit(line, ' ');
	status = lsh_execute(args);
	free(line);
	free(args);
	while (status)
	{
		line = NULL;
		ft_putstr("$> ");
		ft_get_next_line(0, &line);
		args = ft_strsplit(line, ' ');
		status = lsh_execute(args);
		free(line);
		free(args);
	}
}

int						main(int ac, char **av)
{
	int					argc;
	char				**argv;

	argc = ac;
	argv = av;
	mini_loop();
	return (0);
}
