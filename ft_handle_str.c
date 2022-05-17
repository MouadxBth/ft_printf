/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:52:53 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/17 11:11:58 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(int fd, const char *str)
{
	if (fd < 0)
		return (0);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_str(int fd, t_format *format, char *str)
{
	int	result;
	size_t	str_len;

	if (!format)
		return (0);
	result = 0;
	str_len = ft_strlen(str);
	if (format->left_justify)
	{
		result += ft_putstr(fd, str);
		result += ft_repeat_print(fd, ' ', format->left_justify - ft_strlen(str));
	}
	else if (format->minimum_width)
	{
		result += ft_repeat_print(fd, ' ', format->minimum_width - ft_strlen(str));
		result += ft_putstr(fd, str);
	}
	else if (format->precision_flag)
	{
		if (!str)
		{
			if (format->precision >= 6)
				result += write(fd, "(null)", 6);
			else
				return (result);
		}
		else
		{
			if (format->precision <= str_len)
				result += write(fd, str, format->precision);
			else
				result += write(fd, str, str_len);
		}	
	}
	else
		result += ft_putstr(fd, str);
	return (result);
}

int	ft_handle_str(int fd, t_format *format)
{
	return (ft_print_str(fd, format, va_arg(format->args, char *)));
}
