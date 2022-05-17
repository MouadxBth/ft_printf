/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:53:15 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/15 11:41:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int fd, int c)
{
	if (fd < 0)
		return (0);
	return (write(1, &c, 1));
}

int	ft_print_char(int fd, t_format *format, int c)
{
	int	result;

	if (!format)
		return (0);
	result = 0;
	if (format->left_justify)
	{
		result += ft_putchar(fd, c);
		result += ft_repeat_print(fd, ' ', format->left_justify - 1);
	}
	else if (format->minimum_width)
	{
		result += ft_repeat_print(fd, ' ', format->minimum_width - 1);
		result += ft_putchar(fd, c);
	}
	else
		result += ft_putchar(fd, c);
	return (result);
}

int	ft_handle_char(int fd, t_format *format)
{
	return (ft_print_char(fd, format, va_arg(format->args, int)));
}
