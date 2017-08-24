/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pwds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					free_pwd(t_env *tmp2, char *cwd)
{
	free(tmp2->value);
	tmp2->value = ft_strdup(cwd);
}

void					free_old_pwd(t_env *tmp2, char *pwd)
{
	free(tmp2->value);
	tmp2->value = ft_strdup(pwd);
	free(pwd);
}
