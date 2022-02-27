/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:02:53 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 23:23:08 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DECIMAL "0123456789"
#define LOW_HEX "0123456789abcdef"
#define UPP_HEX "0123456789ABCDEF"

static int	ft_get_int(const char *str, int *chars_to_skip)
{
	int	result;
	int	length;

	result = 0;
	length = -1;
	while (ft_isdigit(str[++length]))
		result = (result * 10) + (str[length] - '0');
	*chars_to_skip += length;
	return (result);
}

static int	ft_process_flags(const char *str, t_format *format)
{
	int	index;

        index = 0;
	while (!ft_is_conversion(str[index]))
	{
		if (str[index] == '-')
			format->left_justify = ft_get_int(str + ++index, &index);
		else if (str[index] == '0')
			format->zero_padding = ft_get_int(str + ++index, &index);
		else if (str[index] == '.')
			format->precision = ft_get_int(str + ++index, &index);
		else if (ft_isdigit(str[index]))
			format->minimum_width = ft_get_int(str + index, &index);
	}
        return (index);
}

static int	ft_process_specifiers(const char *str, va_list args)
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

static int	ft_loop(t_format *format, const char *str, ...)
{
	int		index;
	int		bytes_written;

	index = 0;
	bytes_written = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			ft_bzero_format(format);
			index++;
			index += ft_process_flags(str + index, format);
			bytes_written += ft_process_specifiers(str + index, format->args);
		}
		else
			bytes_written += ft_putchar(STD_FD, str[index]);
		index++;
	}
	return (bytes_written);
}
int	ft_printf(const char *str, ...)
{
	t_format	*format;
	int		bytes_written;

	if (!str)
		return (0);
	format = ft_bzero_format(ft_new_format());
	if (!format)
		return (0);
	va_start(format->args, str);
	bytes_written = ft_loop(format, str);
	va_end(format->args);
	free(format);
	return (bytes_written);
}
