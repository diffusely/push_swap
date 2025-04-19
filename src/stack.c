/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:43:33 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 02:34:30 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack **lst, int val)
{
	t_stack	*new;

	if (!lst)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handle("Bad alloc\n");
	new->value = val;
	new->next = NULL;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

void	push_back(t_stack **lst, int val)
{
	t_stack	*new;
	t_stack	*head;

	if (!lst)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error_handle("Bad alloc\n");
	new->value = val;
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
		if (head->next)
		{
			pop_back(lst);
			return ;
		}
		while (head->next->next)
			head = (*lst)->next;
		free(head->next);
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

// void	rotation(t_stack **lst)
// {
// 	if (!lst)
// 		return ;
// 	if (*lst && (*lst)->tail)
// 		ft_swap(&((*lst)->value), &((*lst)->tail->value));
// }
