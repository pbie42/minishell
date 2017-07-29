/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/07/06 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char						*builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int						(*builtin_func[])(char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

int						lsh_num_builtins(void)
{
	return sizeof(builtin_str) / sizeof(char *);
}

int						lsh_cd(char **args)
{
	if(args[1] == NULL)
		ft_putendl("lsh: expected arguments to \"cd\"");
	else
	{
		if(chdir(args[1]) != 0)
			ft_exit("lsh");
		
	}
	return (1);
}

int						lsh_help(char **args)
{
	int					i;
	char					**agv;

	i = 0;
	agv = args;
	ft_putendl("Paul Bie's LSH");
	ft_putendl("Type program names and arguments, and hit enter.");
	ft_putendl("The following are built in:");

	while(i < lsh_num_builtins())
	{
		ft_putendl(builtin_str[i]);
		i++;
	}
	ft_putendl("Use the man command for information on other programs.");
	return (1);
}

int						lsh_exit(char **args)
{
	char					**argv;

	argv = args;
	return (0);
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

int						lsh_execute(char **args)
{
	int					i;

	i = 0;
	if(args[0] == NULL)
		return (1);

	while(i < lsh_num_builtins())
	{
		if(ft_strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
		i++;
	}

	return lsh_launch(args);
}

void						mini_loop(void)
{
	char					**args;
	char					*line;
	int					status;

	line = NULL;
	ft_putstr("$> ");
	ft_get_next_line(0, &line);
	args = ft_strsplit(line, ' ');
	status = lsh_execute(args);
	free(line);
	free(args);
	while(status)
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
	char					**argv;

	argc = ac;
	argv = av;
	mini_loop();
	return (0);
}