/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:27:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/16 16:07:41 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handle(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	valid_input(int argc, char **input)
{
	t_list	*a;
	//int		i;
	int		size;
	char	**str;

	if (argc == 2)
	{
		//i = 0;
		str = ft_split(input[1], &size, ' ');
		if (!str)
			error_handle("Bad alloc\n");
		while (*str)
		{
			t_list *new;
			new = (t_list *)malloc(sizeof(t_list));
			new->next = NULL;
			new->content = malloc(sizeof(int));
			*(int *)new->content = ft_atoi(*str, 1);
			ft_lstadd_front(&a, new);
			str++;
		} 
	}
}
