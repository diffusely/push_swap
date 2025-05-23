/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:31:44 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/24 20:22:44 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	wrong_input(t_stack **a, t_stack **b, char *str)
{
	free_stack(a);
	free_stack(b);
	free(str);
	error_handle("Error\n");
}

static void	check_type(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(a, b, 0);
	else
		wrong_input(a, b, str);
}

void	read_terminal(t_stack **a, t_stack **b)
{
	char	*str;

	if (is_sorted(*a))
	{
		free_stack(a);
		ft_printf("OK\n");
		exit(0);
	}
	while (1)
	{
		str = get_next_line(0);
		if (str)
			check_type(a, b, str);
		else
			break ;
		free(str);
	}
}
