/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:02:53 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 20:08:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DECIMAL "0123456789"
#define LOW_HEX "0123456789abcdef"
#define UPP_HEX "0123456789ABCDEF"

static int	ft_process_formats(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar(STD_FD, va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(STD_FD, va_arg(args, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(STD_FD, va_arg(args, int), 1, DECIMAL));
	else if (*str == 'u')
		return (ft_putnbr(STD_FD, va_arg(args, unsigned int), 0, DECIMAL));
	else if (*str == 'x')
		return (ft_putnbr(STD_FD, va_arg(args, unsigned int), 0, LOW_HEX));
	else if (*str == 'X')
		return (ft_putnbr(STD_FD, va_arg(args, unsigned int), 0, UPP_HEX));
	else if (*str == '%')
		return (write(1, "%", 1));
	else if (*str == 'p')
		return (ft_putptr(STD_FD, va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	int		bytes_written;
	va_list	list;

	if (!str)
		return (0);
	index = 0;
	bytes_written = 0;
	va_start(list, str);
	while (str[index])
	{
		if (str[index] == '%')
			bytes_written += ft_process_formats(str + ++index, list);
		else
			bytes_written += ft_putchar(STD_FD, str[index]);
		index++;
	}
	va_end(list);
	return (bytes_written);
}
