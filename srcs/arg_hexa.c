/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:19:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/11 15:03:05 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_conv_hexa(const char *format, char *buffer, s_arg *argument, int value)
{
	int i;

	if (PTF_FLAG_SPACE(argument->flags))
		*buffer++ = ' ';
	i = ft_log_discret(value, 16) + 1 + ((PTF_FLAG_HASHTAG(argument->flags) &&  value) ? 2 : 0);
	if (PTF_FLAG_ZERO(argument->flags) && value != 0 &&  PTF_FLAG_HASHTAG(argument->flags) && (*buffer++ = '0'))
		*buffer++ = argument->type;
	while (!PTF_FLAG_MINUS(argument->flags) && argument->width-- > i)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			*buffer++ = '0';
		else 
			*buffer++ = ' ';
	}
	if (!PTF_FLAG_ZERO(argument->flags) && value != 0 && PTF_FLAG_HASHTAG(argument->flags) && (*buffer++ = '0'))
		*buffer++ = argument->type;
	ft_unsigned_itoa(value, buffer, 16, 8);
	while (*buffer)
	{
		if (argument->type == 'X' && *buffer >= 'a' && *buffer <= 'f')
			*buffer-=32;
		buffer++;
	}
	while (PTF_FLAG_MINUS(argument->flags) && argument->width-- > i)
		*buffer++ = ' ';
	return (0);
}
