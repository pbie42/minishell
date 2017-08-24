/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_existing_envv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:17:17 by pbie              #+#    #+#             */
/*   Updated: 2016/12/11 15:16:26 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env				*free_first_list_item(t_us *us)
{
	us->holder = us->tmp->next;
	free(us->tmp->var);
	free(us->tmp->value);
	free(us->tmp);
	us->tmp = NULL;
	return (us->holder);
}

void				free_mid_list_item(t_us *us)
{
	us->prev->next = us->tmp->next;
	free(us->tmp->var);
	free(us->tmp->value);
	free(us->tmp);
	us->tmp = NULL;
}

void				free_end_list_item(t_us *us)
{
	free(us->tmp->var);
	free(us->tmp->value);
	free(us->tmp);
	us->tmp = NULL;
	us->prev->next = NULL;
}
