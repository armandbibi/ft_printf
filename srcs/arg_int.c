/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/15 16:16:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_sign(char *buffer, s_arg *argument)
{
	if (argument->is_negative)
	{
		*buffer = '-';
		return (1);
	}
	else if (PTF_FLAG_PLUS(argument->flags))
	{
		*buffer = '+';
		return (1);
	}
	else if (PTF_FLAG_SPACE(argument->flags))
	{
		*buffer = ' ';
		return (1);
	}
	return (0);
}

static int	add_precision(char *buffer, s_arg *argument, char *tmp)
{
	int len;
	int p;
	char *b;

	b = buffer;
	p = argument->precision;
	len = ft_strlen(tmp);
	if (argument->precision == 0 && *tmp == '0')
		return (0);
	while (p > len)
	{
		*buffer = '0';
		buffer++;
		p--;
	}
	while (*tmp)
	{
		*buffer++ = *tmp++;
	}
	return (ft_strlen(b));
}

static int	add_width(char *buffer, s_arg *argument, int len)
{
	int sub;
	int width;
	int pre;
	char *b;

	b = buffer;
	width = argument->width;
	pre = argument->precision;
	sub = (pre > len) ? pre: len;
	if ((argument->is_negative == 1 || PTF_FLAG_PLUS(argument->flags) 
		|| PTF_FLAG_SPACE(argument->flags)))
		width--;
	if (width)
		while (width - 1 >= sub)
		{
			if (PTF_FLAG_ZERO(argument->flags) && !PTF_FLAG_MINUS(argument->flags))
				*buffer++ = '0';
			else
				*buffer++ = ' ';
			width--;
		}
	*buffer = 0;
	return (ft_strlen(b));
}

int			ft_conv_integer(char *buffer, s_arg *argument, intmax_t value)
{
	char	tmp[20];
	int		len;

	char *t;
	t = tmp;
	len = 0;
	ft_cast_itoa(value, t, argument, 10);
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (!PTF_FLAG_ZERO(argument->flags))
			len += add_width(&buffer[len], argument, ft_strlen(tmp));
		len += add_sign(&buffer[len], argument);
		if (PTF_FLAG_ZERO(argument->flags))
			len += add_width(&buffer[len], argument, ft_strlen(tmp));
	}
	if (PTF_FLAG_MINUS(argument->flags))
		len += add_sign(&buffer[len], argument);
	len += add_precision(&buffer[len], argument, tmp);
	if (PTF_FLAG_MINUS(argument->flags))
		len += add_width(&buffer[len], argument, ft_strlen(tmp));
}
