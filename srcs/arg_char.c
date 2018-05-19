/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:53:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/19 15:13:56 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_char(const char *format, char *buffer, s_arg *argument, char value)
{
	if (PTF_FLAG_MINUS(argument->flags))
	{
		if (value != NULL)
			*buffer++ = value;
		else
		{
			*buffer++ = '^';
			*buffer++ = '@';
		}
	}
	while (argument->width-- > 1)
		*buffer++ = ' ';
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (value != NULL)
			*buffer++ = value;
		else
		{
			*buffer++ = '^';
			*buffer++ = '@';
		}
	}
	return (0);
}
