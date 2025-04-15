/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:27:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/15 17:34:33 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

// void	valid_input(char **input)
// {
// 	int	i;

// 	i = 1;
// 	while (input[i])
// 	{
// 		while (input[i][j])
// 		i++;
// 	}
// }
