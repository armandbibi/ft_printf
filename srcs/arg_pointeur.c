/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pointeur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:23:53 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/12 14:53:52 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_pointeur(const char *format, char *buffer, s_arg *argument, int value)
{
	int i;

	if (PTF_FLAG_SPACE(argument->flags))
		*buffer++ = ' ';
	i = ft_log_discret(value, 8) + ((PTF_FLAG_HASHTAG(argument->flags) &&  value) ? 1 : 0);
	if (PTF_FLAG_ZERO(argument->flags) && value != 0 &&  PTF_FLAG_HASHTAG(argument->flags))
		*buffer++ = '0';
	while (!PTF_FLAG_MINUS(argument->flags) && argument->width-- > i +  ((argument->precision > 1) ? argument->precision  : 1))
	{
		if (PTF_FLAG_ZERO(argument->flags))
			*buffer++ = '0';
		else
			*buffer++ = ' ';
	}
	if (!PTF_FLAG_ZERO(argument->flags) && value != 0 && PTF_FLAG_HASHTAG(argument->flags))
		*buffer++ = '0';
	while (argument->precision-- > i + 1 - ((PTF_FLAG_HASHTAG(argument->flags) ? 1 : 0)))
		*buffer++ = '0';
	ft_unsigned_itoa(value, buffer, 16, 8);
	while (*buffer)
	{
		if (argument->type == 'X' && *buffer >= 'a' && *buffer <= 'f')
			*buffer-=32;
		buffer++;
	}
	while (PTF_FLAG_MINUS(argument->flags) && argument->width-- > i +  ((argument->precision > 1) ? argument->precision  : 1))
		*buffer++ = ' ';
	return (0);
}
