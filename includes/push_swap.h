/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:06:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/18 17:25:32 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Validation
void	error_handle(char *message);
void	valid_input(int argc, char **input);

// Free
void	free_split(char **sp);

#endif