/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:06:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/21 00:25:49 by noavetis         ###   ########.fr       */
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
	int				index;
	int				find;
	struct s_stack	*next;
}	t_stack;

// Validation
void	valid_input(t_stack **a, int argc, char **input);

// Free
void	free_split(char **sp);

// List functions
void	push_front(t_stack **lst, int val, int ind);
void	push_back(t_stack **lst, int val, int ind);
void	print_stack(t_stack *lst);
void	pop_front(t_stack **lst);
void	pop_back(t_stack **lst);
int		stack_size(t_stack *a);

// Utils
void	error_handle(char *message);
void	free_all(t_stack **a, char **res, char *r);
void	free_stack(t_stack **lst);
void	ft_swap(int *a, int *b);
int		find_max(t_stack **tmp);
int		find_min(t_stack **tmp);

// Shift up
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// Shift down
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// Push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

// Sort
void	sort_index(t_stack **a);
void	radix_sort(t_stack **a, t_stack **b);
int		is_sorted(t_stack *tmp);


#endif