/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/24 20:34:52 by noavetis         ###   ########.fr       */
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
