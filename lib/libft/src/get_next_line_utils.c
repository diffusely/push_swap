/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:15:43 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/23 17:09:49 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_n(const char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
