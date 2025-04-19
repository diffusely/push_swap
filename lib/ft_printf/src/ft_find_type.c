/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:06:27 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/05 00:57:57 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_type(char ch, va_list args, int *count)
{
	if (ch == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (ch == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (ch == 'p')
		ft_putptr(va_arg(args, unsigned long), count, LHEX);
	else if (ch == 'd' || ch == 'i')
		ft_putnbr(count, va_arg(args, int));
	else if (ch == 'u')
		ft_unsnbr(count, va_arg(args, unsigned int));
	else if (ch == 'x')
		ft_puthex(va_arg(args, unsigned int), count, LHEX);
	else if (ch == 'X')
		ft_puthex(va_arg(args, unsigned int), count, UHEX);
	else if (ch == '%')
		*count += ft_putchar('%');
}
