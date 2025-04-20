/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:15:47 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 23:53:46 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static void	test(t_stack **a, t_stack **b)
// {
// 	ft_printf("\n");
// 	//ra(&a);
// 	print_stack(*a);
// 	push_back(b, 10);
// 	push_back(b, 11);
// 	push_back(b, 12);
// 	while (1)
// 	{
// 		rr(a, b);
// 		ft_printf("stack a\n\n");
// 		print_stack(*a);
// 		ft_printf("stack b\n\n");
// 		print_stack(*b);
// 		ft_printf("\n\n");
// 		sleep(1);
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		error_handle("Error\n");
	}
	a = NULL;
	b = NULL;
	valid_input(&a, argc, argv);
	if (!is_sorted(a))
		radix_sort(&a, &b);
	print_stack(a);
	free_stack(&a);
	return (0);
}
