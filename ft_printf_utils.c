/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:05:14 by lorfanu           #+#    #+#             */
/*   Updated: 2022/01/20 01:15:38 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long long n, const char format)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_printhex(n / 16, format);
		counter += ft_printhex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			counter += ft_printchar(n + '0');
		else
		{
			if (format == 'x')
				counter += ft_printchar(n - 10 + 'a');
			else if (format == 'X')
				counter += ft_printchar(n - 10 + 'A');
		}
	}
	return (counter);
}

int	ft_printptr(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	if (ptr == 0)
		counter += write(1, "0", 1);
	else
		counter += ft_printhex(ptr, 'x');
	return (counter);
}

int	ft_putnbr_u(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n >= 10)
	{
		counter += ft_putnbr_u(n / 10);
		counter += ft_putnbr_u(n % 10);
	}
	else
		counter += ft_printchar(n + '0');
	return (counter);
}
