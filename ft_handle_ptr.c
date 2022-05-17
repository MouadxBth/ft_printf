/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:54:00 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/16 19:45:25 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(int fd, unsigned long n)
{
	return (ft_putstr(fd, "0x") + ft_putnbr(fd, n, 0, "0123456789abcdef"));
}

static int	ft_print_ptr(int fd, t_format *format, unsigned long nbr)
{
	int	result;
	size_t	nbr_len;	

	if (!format)
		return (0);
	if (!nbr)
		return (ft_print_str(fd, format, "(nil)"));
	nbr_len = ft_unsigned_nbrlen(nbr, 16);
	if (format->left_justify)
	{
		result = ft_putptr(fd, nbr);
		result += ft_repeat_print(fd, ' ', format->left_justify - nbr_len - 2);
	}
	else if (format->minimum_width)
	{
		result = ft_repeat_print(fd, ' ', format->minimum_width - nbr_len - 2);
		result += ft_putptr(fd, nbr);
	}
	else
		result = ft_putptr(fd, nbr);
	return (result);
}

int	ft_handle_ptr(int fd, t_format *format)
{
	return (ft_print_ptr(fd, format, va_arg(format->args, unsigned long)));
}
