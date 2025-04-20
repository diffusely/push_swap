/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:08:43 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/21 01:19:29 by noavetis         ###   ########.fr       */
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
			pb(a, b);
			rb(b);
			i++;
			pushed++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b);
			i++;
			pushed++;
		}
		else
			ra(a);
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
				rb(b);
		else
			while (pos++ < size)
				rrb(b);
		pa(a, b);
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks(a, b, chunk_size);
	pa_back(a, b);
}
