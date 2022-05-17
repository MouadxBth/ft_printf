/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:56:23 by mbouthai          #+#    #+#             */
/*   Updated: 2022/05/17 10:19:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_sign(int fd, t_format *format, int nbr)
{
	int	result;

	result = 0;
	if (format->sign_precedence)
	{
		if (nbr < 0)
			result = ft_putchar(fd, '-');
		else
			result = ft_putchar(fd, '+');
	}
	else if (format->sign_replacement)
	{
		if (nbr < 0)
			result = ft_putchar(fd, '-');
		else
			result = ft_putchar(fd, ' ');
	}
	else if (nbr < 0)
		result = ft_putchar(fd, '-');
	return (result);
}

signed int	ft_handle_signed_padding(int fd, t_format *format, long long nbr)
{
	int	result;
	int	amount;

	result = 0;
	if (format->precision)
	{
		amount = format->precision - ft_signed_nbrlen(nbr, 10);
		if (nbr >= 0 && (format->sign_precedence || format->sign_replacement))
			amount--;
		if (nbr < 0)
			amount++;
		result += ft_repeat_print(fd, '0', amount);
	}
	else if (format->zero_padding && !(format->left_justify || format->minimum_width))
	{
		amount = format->zero_padding - ft_signed_nbrlen(nbr, 10);
		if (nbr >= 0 && (format->sign_precedence || format->sign_replacement))
			amount--;
		result += ft_repeat_print(fd, '0', amount);
	}
	return (result);
}

static int	ft_print_signed(int fd, t_format *format, int nbr, char *base)
{
	int	result;
	int	nbr_len;

	result = 0;
	nbr_len = ft_signed_nbrlen(nbr, 10);
	if (format->left_justify)
	{
		result = ft_handle_sign(fd, format, nbr) + ft_putnbr(fd, nbr, 1, base);
		result += ft_repeat_print(fd, ' ', format->left_justify - result);
	}
	else if (format->minimum_width)
	{
		if ((format->sign_precedence || format->sign_replacement) && nbr >= 0)
			nbr_len++;
		result = ft_repeat_print(fd, ' ', format->minimum_width - nbr_len);
		result += ft_handle_sign(fd, format, nbr) + ft_putnbr(fd, nbr, 1, base);
	}
	else
	{
		result = ft_handle_sign(fd, format, nbr) + ft_handle_signed_padding(fd, format, nbr);
		result += ft_putnbr(fd, nbr, 1, base);
	}
	return (result);
}

int	ft_handle_signed(int fd, t_format *format)
{
	if (!format)
		return (0);
	return (ft_print_signed(fd, format, va_arg(format->args, int), "0123456789"));
}
