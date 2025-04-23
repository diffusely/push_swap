/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:12:35 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/23 21:07:06 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		chunk_sort(&a, &b);
	free_stack(&a);
	return (0);
}
