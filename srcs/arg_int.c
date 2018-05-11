/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/09 22:24:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_conv_integer(const char *format, char *buffer, s_arg *argument, int value)
{
	int i;

	if (PTF_FLAG_SPACE(argument->flags))
		*buffer++ = ' ';
	i = ft_log_discret(value, 10) + 1;
	while (argument->precision-- > i)
	   *buffer++ = '0';	
	ft_itoa(value, buffer, 10);
	return (0);
}
