/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:45:20 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/23 17:27:04 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	down(t_stack **tmp)
{
	t_stack	*head;

	head = *tmp;
	while (head->next)
		head = head->next;
	push_front(tmp, head->value, head->index);
	pop_back(tmp);
}

void	rra(t_stack **a, int flag)
{
	if (!a)
		return ;
	if (*a)
	{
		down(a);
		if (flag)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, int flag)
{
	if (!b)
		return ;
	if (*b)
	{
		down(b);
		if (flag)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	if (!a || !b)
		return ;
	if (*a)
		down(a);
	if (*b)
		down(b);
	if (flag)
		ft_printf("rrr\n");
}
