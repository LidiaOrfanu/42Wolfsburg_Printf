/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:27:06 by lorfanu           #+#    #+#             */
/*   Updated: 2022/01/20 00:34:06 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_putnbr(int n);
int	ft_printstr(char *str);
int	ft_handle_conversion(const char format, va_list pargs);
int	ft_printhex(unsigned long long n, const char format);
int	ft_printptr(unsigned long long ptr);
int	ft_putnbr_u(unsigned int n);

#endif
