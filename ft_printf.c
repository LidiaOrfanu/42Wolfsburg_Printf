/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:27:09 by lorfanu           #+#    #+#             */
/*   Updated: 2022/01/20 01:31:08 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		counter;

	counter = 0;
	nb = n;
	if (nb < 0)
	{
		nb = (-1) * nb;
		write(1, "-", 1);
		counter++;
	}
	if (nb >= 10)
		counter += ft_putnbr(nb / 10);
	counter += ft_printchar((nb % 10) + '0');
	return (counter);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i])
		{
			ft_printchar(str[i]);
			i++;
		}
	}
	return (i);
}

int	ft_handle_conversion(const char format, va_list pargs)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_printchar(va_arg(pargs, int));
	else if (format == 's')
		counter += ft_printstr(va_arg(pargs, char *));
	else if (format == 'p')
		counter += ft_printptr(va_arg(pargs, unsigned long long));
	else if (format == 'd')
		counter += ft_putnbr(va_arg(pargs, int));
	else if (format == 'i')
		counter += ft_putnbr(va_arg(pargs, int));
	else if (format == 'u')
		counter += ft_putnbr_u(va_arg(pargs, unsigned int));
	else if (format == 'x')
		counter += ft_printhex(va_arg(pargs, unsigned int), format);
	else if (format == 'X')
		counter += ft_printhex(va_arg(pargs, unsigned int), format);
	else if (format == '%')
		counter += ft_printchar('%');
	return (counter);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	va_list	pargs;
	int		i;

	i = 0;
	counter = 0;
	if (!format)
		return (-1);
	va_start(pargs, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			counter += ft_handle_conversion(format[i + 1], pargs);
			i++;
		}
		else
				counter += ft_printchar(format[i]);
		i++;
	}
	va_end(pargs);
	return (counter);
}
