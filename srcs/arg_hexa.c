/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:19:21 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/10 20:39:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_conv_hexa(const char *format, char *buffer, s_arg *argument, int value)
{
	int i;

	if (PTF_FLAG_SPACE(argument->flags))
		*buffer++ = ' ';
	if (PTF_FLAG_HASHTAG(argument->flags)&& PTF_FLAG_ZERO(argument->flags) && value != 0 && (*buffer++ = '0'))
		*buffer++ = argument->type;
	i = ft_log_discret(value, 16) + (PTF_FLAG_HASHTAG(argument->flags) ? 3 : 1);
	while (!PTF_FLAG_MINUS(argument->flags) && argument->width-- > i)
	{
		if(PTF_FLAG_ZERO(argument->flags))
			*buffer++ = '0';
		else
			*buffer++ = ' ';
	}
	if (PTF_FLAG_HASHTAG(argument->flags)&& !PTF_FLAG_ZERO(argument->flags) && value != 0 && (*buffer++ = '0'))
		*buffer++ = argument->type;
	if (value != 0 && argument->precision != 0)
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
