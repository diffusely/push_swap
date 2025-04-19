/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 01:15:31 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 01:15:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		sp[i] = NULL;
		i++;
	}
	free(sp);
	sp = NULL;
}

void	free_all(t_stack **a, char **res, char *r)
{
	free_split(res);
	free(r);
	free_stack(a);
	error_handle("Error1\n");
}

void	free_stack(t_stack **lst)
{
	while (lst && *lst)
		pop_front(lst);
	*lst = NULL;
}
