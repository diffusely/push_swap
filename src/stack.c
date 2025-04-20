/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:43:33 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/21 01:27:32 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack **lst, int val, int ind)
{
	t_stack	*new;

	if (!lst)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handle("Bad alloc\n");
	new->value = val;
	new->index = ind;
	new->next = NULL;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

void	push_back(t_stack **lst, int val, int ind)
{
	t_stack	*new;
	t_stack	*head;

	if (!lst)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handle("Bad alloc\n");
	new->value = val;
	new->index = ind;
	new->next = NULL;
	if (*lst)
	{
		head = *lst;
		while (head->next)
			head = head->next;
		head->next = new;
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

void	pop_back(t_stack **lst)
{
	t_stack	*head;

	if (lst && *lst)
	{
		head = *lst;
		if (!head->next)
		{
			pop_front(lst);
			lst = NULL;
			return ;
		}
		while (head->next->next)
			head = head->next;
		free(head->next);
		head->next = NULL;
	}
}

int	stack_size(t_stack *a)
{
	int	c;

	c = 0;
	while (a)
	{
		c++;
		a = a->next;
	}
	return (c);
}
