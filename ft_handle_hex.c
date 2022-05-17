/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:59:33 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/17 10:27:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_handle_alt_form(int fd, t_format *format, int uppercase)
{
	int	result;

	result = 0;
	if (format->alt_form) {
		if (uppercase)
			result = ft_putstr(fd, "0X");
		else
			result = ft_putstr(fd, "0x");
	}
	return (result);
}

static int	ft_handle_unsigned_padding(int fd, t_format *format, unsigned long nbr)
{
	int	result;
	int	amount;

	result = 0;
	if (format->precision)
	{
		amount = format->precision - ft_unsigned_nbrlen(nbr, 16);
		result += ft_repeat_print(fd, '0', amount);
	}
	else if (format->zero_padding && !(format->left_justify || format->minimum_width))
	{
		amount = format->zero_padding - ft_unsigned_nbrlen(nbr, 16);
		if (format->alt_form)
			amount -= 2;
		result += ft_repeat_print(fd, '0', amount);
	}
	return (result);
}

static int	ft_print_hex(int fd, t_format *format, unsigned int nbr, int uppercase)
{
	int		result;
	char		*base;
	int		nbr_len;

	if (!format)
		return (0);
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	nbr_len = ft_unsigned_nbrlen(nbr, 16);
	if (format->alt_form)
		nbr_len += 2;
	if (format->left_justify)
	{
		result = ft_handle_alt_form(fd, format, uppercase) + ft_putnbr(fd, nbr, 0, base);
		result += ft_repeat_print(fd, ' ', format->left_justify - nbr_len);
	}
	else if (format->minimum_width)
	{
		result = ft_repeat_print(fd, ' ', format->minimum_width - nbr_len);
		result += ft_handle_alt_form(fd, format, uppercase) + ft_putnbr(fd, nbr, 0, base);
	}
	else
	{
		result = 0;
		if (nbr)
			result += ft_handle_alt_form(fd, format, uppercase);
		result += ft_handle_unsigned_padding(fd, format, nbr);
		result += ft_putnbr(fd, nbr, 0, base);
	}
	return (result);
}

int	ft_handle_hex(int fd, t_format *format, int uppercase)
{
	return (ft_print_hex(fd, format, va_arg(format->args, unsigned int), uppercase));
}

