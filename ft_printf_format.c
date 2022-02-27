/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:21:14 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 23:19:40 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_new_format(void)
{
	t_format	*result;

	result = (t_format *)malloc(sizeof(t_format));
	if (!result)
		return (NULL);
	return (result);
}

t_format	*ft_bzero_format(t_format *format)
{
	if (!format)
		return (NULL);
	format->left_justify = 0;
	format->minimum_width = 0;
	format->zero_padding = 0;
	format->precision = 0;
	return (format);
}
