/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:53:30 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 18:08:24 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnbr_base(int fd, unsigned long n, char *base, size_t radix)
{
        long	nbr;

	nbr = n;
	if ((size_t) nbr < radix)
		ft_putchar(fd, base[nbr]);
	else
	{
		ft_printnbr_base(fd, nbr / radix, base, radix);
		ft_printnbr_base(fd, nbr % radix, base, radix);
	}
}

int     ft_putnbr(int fd, long n, int is_signed, char *base)
{
	size_t	radix;

	if (fd < 0)
		return (0);
	radix = ft_strlen(base);
	if (radix <= 0)
		return (0);
	if (is_signed)
	{
		if (n < 0)
		{
			ft_putchar(fd, '-');
			n *= -1;
		}
	}	
	ft_printnbr_base(fd, n, base, radix);
	return (ft_nbrlen(n, is_signed, radix));
}
