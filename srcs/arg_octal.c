/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:47:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/09 22:35:21 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int     ft_conv_octal(const char *format, char *buffer, s_arg *argument, int value)
{
	int i;

	i = 0;
	if (PTF_FLAG_SPACE(argument->flags))
	{
		i++;
		*buffer++ = ' ';
	}
	i += ft_log_discret(10, 8) + 1;
	if (PTF_FLAG_MINUS(argument->flags))
		buffer = ft_itoa(value, buffer, 8);
	while (argument->precision-- > i)
		*buffer++ = '0';
	if (!PTF_FLAG_MINUS(argument->flags))
		buffer = ft_itoa(value, buffer, 8);
	return (i);
}
