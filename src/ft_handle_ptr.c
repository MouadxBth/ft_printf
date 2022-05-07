/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:54:00 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 19:52:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(int fd, unsigned long n)
{
	if (!n)
		return (ft_putstr(fd, "(nil)"));
	return (ft_putstr(fd, "0x") + ft_putnbr(fd, n, 0, "0123456789abcdef"));
}
