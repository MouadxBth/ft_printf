/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:53:30 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 21:05:28 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_print_nbr(int fd, unsigned long n, char *base, size_t radix)
{
	unsigned long	nbr;
	size_t			result;

	nbr = n;
	result = 0;
	if ((size_t) nbr < radix)
		result += ft_putchar(fd, base[nbr]);
	else
	{
		result += ft_print_nbr(fd, nbr / radix, base, radix);
		result += ft_print_nbr(fd, nbr % radix, base, radix);
	}
	return (result);
}

int	ft_putnbr(int fd, long long n, int is_signed, char *base)
{
	size_t	radix;
	int		result;

	if (fd < 0)
		return (0);
	radix = ft_strlen(base);
	if (radix <= 0)
		return (0);
	result = 0;
	if (is_signed)
	{
		if (n < 0)
		{
			result += ft_putchar(fd, '-');
			n *= -1;
		}
	}	
	result += ft_print_nbr(fd, n, base, radix);
	return (result);
}
