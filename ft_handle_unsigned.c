/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:30:25 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/17 11:29:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_unsigned_padding(int fd, t_format *format, unsigned long nbr)
{
	int	result;
	int	amount;

	result = 0;
	if (format->precision)
	{
		amount = format->precision - ft_unsigned_nbrlen(nbr, 10);
		if (format->sign_precedence || format->sign_replacement)
			amount--;
		result += ft_repeat_print(fd, '0', amount);
	}
	else if (format->zero_padding && !(format->left_justify || format->minimum_width))
	{
		amount = format->zero_padding - ft_unsigned_nbrlen(nbr, 10);
		if (format->sign_precedence || format->sign_replacement)
			amount--;
		result += ft_repeat_print(fd, '0', amount);
	}
	return (result);
}
static int	ft_print_unsigned(int fd, t_format *format, unsigned long nbr)
{
	int	result;
	char	*base;

	if (!format)
		return (0);
	base = "0123456789";
	if (format->left_justify)
	{
		result = ft_putnbr(fd, nbr, 0, base);
		result += ft_repeat_print(fd, ' ', format->left_justify - result);
	}
	else if (format->minimum_width)
	{
		result = ft_repeat_print(fd, ' ', format->minimum_width - ft_unsigned_nbrlen(nbr, 10));
		result += ft_putnbr(fd, nbr, 0, base);
	}
	else
		result = ft_handle_unsigned_padding(fd, format, nbr) + ft_putnbr(fd, nbr, 0, base);
	return (result);
}

int	ft_handle_unsigned(int fd, t_format *format)
{
	return (ft_print_unsigned(fd, format, va_arg(format->args, unsigned int)));
}

