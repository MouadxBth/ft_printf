/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:28:32 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/20 13:11:15 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_str(const char *str, va_list args)
{
	char	a;
	if (*str == 'c')
	{
		a = va_arg(args, int);
		return (write(1, &a, 1));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	bytes_written;
	va_list	args;

	bytes_written = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_parse_str(str + 1, args);
			str++;
		}
		else
			bytes_written += write(1, str, 1);
		str++;
	}
	return (bytes_written);
}
