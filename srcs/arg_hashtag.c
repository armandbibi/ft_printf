/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hashtag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:36:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/09 23:16:48 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_conv_hashtag(const char *format, char *buffer, s_arg *argument, int value)
{
	int len;

	len = 0;
	if (PTF_FLAG_MINUS(argument->flags))
		*buffer++ = '%';
	while (argument->width-- > 1)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			*buffer++ = '0';
		else
			*buffer++ = ' ';
	}
	if (!PTF_FLAG_MINUS(argument->flags))
		*buffer = '%';
	return (len + 1 + argument->width);
}
