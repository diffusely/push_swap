/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimaze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:34:17 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/28 18:52:50 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack **a, int add)
{
	if ((*a)->index == add)
	{
		ra(a, 1);
		if ((*a)->index == 2 + add)
		{
			sa(a, 1);
			rra(a, 1);
			return ;
		}
		sa(a, 1);
	}
	else if ((*a)->index == 1 + add)
	{
		rra(a, 1);
		if ((*a)->index == 2 + add)
		{
			ra(a, 1);
			sa(a, 1);
		}
	}
}

static void	helper(t_stack *temp, int *pos, int *i)
{
	*(pos) = 0;
	while (temp)
	{
		if (temp->index == *i)
			break ;
		++(*pos);
		temp = temp->next;
	}
}

static void	help(t_stack **a, t_stack **b, int size, int *i)
{
	int	pos;

	while (size > 3)
	{
		helper(*a, &pos, i);
		while (*i < 2)
		{
			if ((*a)->index == 0 || (*a)->index == 1)
			{
				pb(a, b, 1);
				--size;
				++(*i);
			}
			else if (pos <= size / 2)
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
	if ((*b)->index == 0)
		rb(b, 1);
}

static void	sort_5(t_stack **a, t_stack **b, int size)
{
	int		i;

	i = 0;
	if ((*a)->index == 4 && (*a)->next->index == 1
		&& (*a)->next->next->index == 0
		&& (*a)->next->next->next->index == 2)
	{
		ra(a, 1);
		sa(a, 1);
		return ;
	}
	help(a, b, size, &i);
	if (!is_sorted(*a))
		sort_3(a, i);
	if ((*a)->index == 2 + i)
	{
		ra(a, 1);
		if ((*a)->index == 1 + i)
			sa(a, 1);
	}
	while (*b)
		pa(a, b, 1);
}

void	sort_help(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
	{
		sort_3(a, 0);
		if ((*a)->index == 2 && size == 3)
		{
			ra(a, 1);
			if ((*a)->index == 1)
				sa(a, 1);
		}
		return ;
	}
	else if (size > 3)
		sort_5(a, b, size);
}
