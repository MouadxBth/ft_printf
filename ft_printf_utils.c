/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:05:21 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 18:26:43 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	ft_nbrlen(long n, int is_signed, int base)
{
	size_t	length;
	long	nbr;

	length = 0;
	nbr = n;
	if (is_signed && n < 0)
	{
		length++;
		nbr *= -1;
	}
	else
		nbr = (unsigned long) n;
	while (nbr)
	{
		nbr /= base;
		length++;
	}
	return (length);
}
