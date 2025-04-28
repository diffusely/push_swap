/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:27:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/04/24 20:20:52 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	valid_input_number(const char *str, int *size)
{
	int	temp;

	temp = *size;
	if (!(*str))
		error_handle("Error\n");
	while (*str)
	{
		while (*str && ((*str >= 9 && *str <= 13) || (*str == ' ')))
			str++;
		if (*str == '-' || *str == '+')
			if (!(*(++str)))
				error_handle("Error\n");
		if (*str && !ft_isdigit(*str))
			error_handle("Error\n");
		if (*str && ft_isdigit(*str))
			++(*size);
		while (*str && ft_isdigit(*str))
			str++;
		if (*str && !((*str >= 9 && *str <= 13) || (*str == ' ')))
			error_handle("Error\n");
	}
	if (*size == temp)
		error_handle("Error\n");
}

static void	pars_null(char *str)
{
	int		i;
	char	sign;
	int		j;

	i = 0;
	sign = '0';
	j = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		sign = str[i++];
	while (str[i] && str[i] == '0')
		++i;
	if (!str[i])
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	if (sign == '-')
		str[j++] = sign;
	while (str[i])
		str[j++] = str[i++];
	str[j] = '\0';
}

static void	valid_ret_num(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if ((*a)->next)
	{
		first = *a;
		while (first)
		{
			second = first->next;
			while (second)
			{
				if (first->value == second->value)
				{
					free_stack(a);
					error_handle("Error\n");
				}
				second = second->next;
			}
			first = first->next;
		}
	}
}

static void	valid_number(t_stack **a, int argc, char **input)
{
	int		i;
	int		j;
	int		id;
	char	**res;
	char	*r;

	i = 0;
	id = 0;
	while (++i < argc)
	{
		res = ft_split(input[i], ' ');
		j = -1;
		while (res[++j])
		{
			r = ft_itoa(ft_atoi(res[j]));
			pars_null(res[j]);
			push_back(a, ft_atoi(res[j]), id++);
			if (ft_strncmp(r, res[j], ft_strlen(r)))
				free_all(a, res, r);
			free(r);
		}
		free_split(res);
	}
}

void	valid_input(t_stack **a, int argc, char **input)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
		valid_input_number(input[i++], &size);
	valid_number(a, argc, input);
	valid_ret_num(a);
	sort_index(a);
}
