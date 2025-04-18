/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:27:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/18 18:36:39 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

static void	valid_number(const char *str)
{
	while (*str)
	{
		while (*str && ((*str >= 9 && *str <= 13) || (*str == ' ')))
			str++;
		if (*str == '-')
			str++;
		else if (*str == '+')
			str++;
		while (*str && ft_isdigit(*str))
			str++;
		if (*str != ' ')
			break ;
	}
	if (*str)
		error_handle("Error\n");
}

void	valid_input(int argc, char **input)
{
	int	i;

	i = 1;
	while (i < argc)
		valid_number(input[i++]);
}
