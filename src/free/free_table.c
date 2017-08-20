/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:16:39 by pbie              #+#    #+#             */
/*   Updated: 2017/09/19 15:19:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void						free_table(char **array)
{
	int					i;
	int					x;

	i = 0;
	x = -1;
	if (array == NULL || array[0] == NULL)
		return ;
	while (array[i] != NULL)
		i++;
	while (++x < i)
		free(array[x]);
	free(array);
}