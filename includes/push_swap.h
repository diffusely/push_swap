/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:06:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/24 20:45:50 by noavetis         ###   ########.fr       */
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

void	valid_input(t_stack **a, int argc, char **input);
void	free_split(char **sp);
void	push_front(t_stack **lst, int val, int ind);
void	push_back(t_stack **lst, int val, int ind);
void	pop_front(t_stack **lst);
void	pop_back(t_stack **lst);
int		stack_size(t_stack *a);

void	error_handle(char *message);
void	free_all(t_stack **a, char **res, char *r);
void	free_stack(t_stack **lst);
void	ft_swap(int *a, int *b);
int		find_max(t_stack **tmp);
int		find_min(t_stack **tmp);

void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);
void	pa(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **a, t_stack **b, int flag);

void	sort_index(t_stack **a);
void	chunk_sort(t_stack **a, t_stack **b);
int		is_sorted(t_stack *tmp);
void	sort_help(t_stack **a, t_stack **b, int size);

#endif