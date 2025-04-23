/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:08:43 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/23 21:06:57 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index_pos(t_stack *b)
{
	int		max;
	int		i;
	int		pos;
	t_stack	*tmp;

	max = b->index;
	pos = 0;
	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;
	int	pushed;
	int	size;

	i = 0;
	pushed = 0;
	size = stack_size(*a);
	while (pushed < size)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
			pushed++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, 1);
			i++;
			pushed++;
		}
		else
			ra(a, 1);
	}
}

static void	pa_back(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_index_pos(*b);
		if (pos <= size / 2)
			while (pos--)
				rb(b, 1);
		else
			while (pos++ < size)
				rrb(b, 1);
		pa(a, b, 1);
	}
}

static void	radix_help(t_stack **a)
{
	if ((*a)->index == 0)
	{
		ra(a, 1);
		sa(a, 1);
		if ((*a)->index == 2)
			rra(a, 1);
	}
	else if ((*a)->index == 1)
	{
		rra(a, 1);
		if ((*a)->index == 2)
		{
			ra(a, 1);
			sa(a, 1);
		}
	}
	else if ((*a)->index == 2)
	{
		ra(a, 1);
		if ((*a)->index == 1)
			sa(a, 1);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	if (size == 2)
	{
		sa(a, 1);
		return ;
	}
	if (size == 3)
	{
		radix_help(a);
		return ;
	}
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(a, b, chunk_size);
	pa_back(a, b);
}
