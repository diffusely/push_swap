/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:43:33 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 01:16:35 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack **lst, int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handle("Bad alloc\n");
	new->value = val;
	new->next = NULL;
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

void	pop_front(t_stack **lst)
{
	t_stack	*head;

	if (lst && *lst)
	{
		head = (*lst)->next;
		free(*lst);
		*lst = head;
	}
}

void	print_stack(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->value);
		lst = lst->next;
	}
}
