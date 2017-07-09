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

#include "ft_ls.h"

char						*read_line(void)
{
	char					*line;

	line = NULL;
	ft_get_next_line(0, &line);
	return line;
}

void						mini_loop(void)
{
	char					*line;
	char					**args;
	int					status;

	line = read_line();
	args = ft_strsplit(line, ' ');
	status = execute(args);
	free(line);
	free(args);
	while(status)
	{
		line = read_line();
		args = ft_strsplit(line, ' ');
		status = execute(args);
		free(line);
		free(args);
	}
	
}

int						main(int ac, char **av)
{
	mini_loop();
	return (0);
}