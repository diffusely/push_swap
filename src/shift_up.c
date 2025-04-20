/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 02:21:39 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 23:41:22 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	up(t_stack **tmp)
{
	push_back(tmp, (*tmp)->value, (*tmp)->index);
	pop_front(tmp);
}

void	ra(t_stack **a)
{
	if (!a)
		return ;
	if (*a)
	{
		up(a);
		ft_printf("ra\n");
	}
}

void	rb(t_stack **b)
{
	if (!b)
		return ;
	if (*b)
	{
		up(b);
		ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return ;
	if (*a)
		up(a);
	if (*b)
		up(b);
	ft_printf("rr\n");
}
