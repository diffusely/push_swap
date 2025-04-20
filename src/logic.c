/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/21 00:28:43 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*copy_stack(t_stack **a)
{
	t_stack	*head;
	t_stack	*res;

	res = NULL;
	head = *a;
	while (head)
	{
		push_back(&res, head->value, head->index);
		head = head->next;
	}
	return (res);
}

static void	sort_stack(t_stack **a)
{
	t_stack	*tmp;
	int		sorted;

	if (!a || !(*a))
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = *a;
		while (tmp->next)
		{
			if (tmp->value > tmp->next->value)
			{
				ft_swap(&(tmp->value), &(tmp->next->value));
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
}

void	sort_index(t_stack **a)
{
	t_stack	*copy;
	t_stack	*head;
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	head = *a;
	copy = copy_stack(a);
	sort_stack(&copy);
	while (head)
	{
		tmp = copy;
		while (tmp)
		{
			if (head->value == tmp->value)
			{
				head->index = tmp->index;
				break ;
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
	free_stack(&copy);
}

static void	radix_helper(t_stack **a, t_stack **b, int *i, int size, int *count, int max)
{
	if (is_sorted(*a))
		return ;
	while (size--)
	{
		
		ft_printf("****a*******\n");
		print_stack(*a);
		ft_printf("************\n");
		ft_printf("*****b******\n");
		print_stack(*b);
		ft_printf("************\n");
		if ((*a)->index == max + *count)
		{
			ra(a);
			++(*count);
			ft_printf("****a*******\n");
			print_stack(*a);
			ft_printf("************\n");
			ft_printf("*****b******\n");
			print_stack(*b);
			ft_printf("************\n");
		}
		else if ((((*a)->index >> *i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		if (!(*b) && is_sorted(*a))
			return ;
	}
	// if ((*b)->index == find_min(*b) + *count)
	// {
	// 	rrb(b);
	// 	sb(b);
	// 	rb(b);
	// 	rb(b);
	// 	++(*count);
	// }
	while (*b)
		pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max;
	int	max_bits;
	int	size;
	int	i;
	int	count;

	count = 0;
	size = stack_size(*a);
	max = find_min(a);
	ft_printf("%d\n", max);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		++max_bits;
	++max_bits;
	i = 0;
	while (i < max_bits)
	{
		radix_helper(a, b, &i, size, &count, max);
		++i;
	}
}
