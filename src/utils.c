/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:22:36 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/21 00:27:39 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	find_max(t_stack **tmp)
{
	t_stack	*head;
	int		max;

	if (!tmp)
		return (0);
	max = (*tmp)->index;
	head = (*tmp);
	while (head)
	{
		ft_printf("%d\n", head->index);
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	return (max);
}

int	find_min(t_stack **tmp)
{
	t_stack	*head;
	int		min;

	if (!tmp)
		return (0);
	min = (*tmp)->index;
	head = (*tmp);
	while (head)
	{
		ft_printf("%d\n", head->index);
		if (min > head->index)
			min = head->index;
		head = head->next;
	}
	return (min);
}

int	is_sorted(t_stack *tmp)
{
	t_stack	*head;
	int		id;

	if (!tmp)
		return (0);
	id = 0;
	head = tmp;
	while (head->next)
	{
		if (id != head->index)
			return (0);
		++id;
		head = head->next;
	}
	return (1);
}
