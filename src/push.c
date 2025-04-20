/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:04:21 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 19:04:08 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	if (*b)
	{
		push_front(a, (*b)->value, (*b)->index);
		pop_front(b);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
	if (*a)
	{
		push_front(b, (*a)->value, (*a)->index);
		pop_front(a);
		ft_printf("pb\n");
	}
}
