/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:09:14 by noavetis          #+#    #+#             */
/*   Updated: 2025/02/04 22:14:39 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(size_t num, int *count, char *hex)
{
	if (num == 0)
		*count += (write(1, "(nil)", 5));
	else
	{
		*count += write(1, "0x", 2);
		ft_puthex(num, count, hex);
	}
}

void	ft_unsnbr(int *count, unsigned int n)
{
	char	c;

	if (n == 0)
		*count += write(1, "0", 1);
	else
	{
		c = (n % 10) + '0';
		n /= 10;
		if (n == 0)
		{
			*count += write(1, &c, 1);
			return ;
		}
		ft_putnbr(count, n);
		*count += write(1, &c, 1);
	}
}

void	ft_puthex(size_t num, int *count, char *hex)
{
	int		index;

	if (num == 0)
	{
		*count += write(1, "0", 1);
		return ;
	}
	index = num % 16;
	num /= 16;
	if (num == 0)
	{
		*count += write(1, &hex[index], 1);
		return ;
	}
	ft_puthex(num, count, hex);
	*count += write(1, &hex[index], 1);
}

void	ft_putnbr(int *count, int n)
{
	char	c;

	if (n == 0)
		*count += write(1, "0", 1);
	else if (n == -2147483648)
		*count += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			*count += write(1, "-", 1);
		}
		c = (n % 10) + '0';
		n /= 10;
		if (n == 0)
		{
			*count += write(1, &c, 1);
			return ;
		}
		ft_putnbr(count, n);
		*count += write(1, &c, 1);
	}
}
