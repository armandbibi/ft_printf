/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:28:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/09 22:16:39 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_string(const char *format, char *buffer, s_arg *argument, char *value)
{
	int len = ft_strlen(value);
	if (PTF_FLAG_MINUS(argument->flags))
	{
		while (*value)
			*buffer++ = *value++;
	}
	while (WIDTH > len)
	{
		*buffer++ = ' ';
		WIDTH--;
	}
	if (!PTF_FLAG_MINUS(argument->flags))
		ft_strncpy(buffer, value, len);
	return 0;
}
