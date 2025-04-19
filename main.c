/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:03:37 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 02:34:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//static void	test(t_stack **a)
//{
	// push_back(&a, 2);
	// push_back(&a, 10);
	// push_back(&a, 3);
	// push_front(&a, 9);
	// print_stack(a);
	// ft_printf("\n");
	// pop_front(&a);
	// pop_front(&a);
	// print_stack(a);
	// free_stack(&a);
	// ft_printf("\n");
	// print_stack(a);
//}

int	main(int argc, char **argv)
{
	(void)argv;
	t_stack	*a;
	//t_stack	*b;
	if (argc < 2)
	{
		error_handle("Error\n");
	}
	valid_input(&a, argc, argv);
	ft_printf("\n");
	ra(&a);
	print_stack(a);
	ra(&a);
	ra(&a);
	ra(&a);
	ft_printf("\n");
	print_stack(a);
	return (0);
}
