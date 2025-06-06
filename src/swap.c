/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:13:50 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/23 22:07:39 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_stack **tmp)
{
	t_stack	*temp;

	temp = (*tmp)->next;
	(*tmp)->next = (*tmp)->next->next;
	temp->next = (*tmp);
	*tmp = temp;
}

void	sa(t_stack **a, int flag)
{
	if (!a)
		return ;
	if (*a && (*a)->next)
	{
		stack_swap(a);
		if (flag)
			ft_printf("sa\n");
	}
}

void	sb(t_stack **b, int flag)
{
	if (!b)
		return ;
	if (*b && (*b)->next)
	{
		stack_swap(b);
		if (flag)
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	if (!a || !b)
		return ;
	if (*a)
		stack_swap(a);
	if (*b)
		stack_swap(b);
	if (flag)
		ft_printf("ss\n");
}
