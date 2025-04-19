/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:06:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/20 02:43:40 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

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
void	valid_input(t_stack **a, int argc, char **input);
void	valid_number(t_stack **a, int argc, char **input);

// Free
void	free_split(char **sp);


// List functions
void	push_front(t_stack **lst, int val);
void	push_back(t_stack **lst, int val);
void	print_stack(t_stack *lst);
void	pop_front(t_stack **lst);
void	rotation(t_stack **lst);
void	pop_back(t_stack **lst);


// Utils
void	error_handle(char *message);
void	free_all(t_stack **a, char **res, char *r);
void	free_stack(t_stack **lst);
void	ft_swap(int *a, int *b);

// Operations
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

#endif