/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:10:28 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/24 20:02:35 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	read_terminal(&a, &b);
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	return (0);
}
