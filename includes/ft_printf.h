/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:27:29 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/05 00:58:44 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

void	ft_puthex(size_t num, int *count, char *hex);
void	ft_putnbr(int *count, int n);
void	ft_unsnbr(int *count, unsigned int n);
void	ft_putptr(size_t num, int *count, char *hex);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
void	ft_find_type(char ch, va_list args, int *count);
int		ft_printf(const char *str, ...);
int		ft_check(char c);

#endif