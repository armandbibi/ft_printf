/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/28 19:45:01 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_precision(char *buffer, s_arg *argument, char *tmp)
{
	int		len;
	int		p;
	char	*b;

	b = buffer;
	p = argument->precision;
	len = ft_strlen(tmp);
	if (argument->precision == 0 && *tmp == '0')
		return (0);
	while (p-- > len)
		write_buffer(&buffer, '0');
	while (*tmp)
		write_buffer(&buffer, *tmp++);
	return (ft_strlen(b));
}

static int	add_width(char *buffer, s_arg *argument, int len, int value)
{
	int		sub;
	int		width;
	int		pre;
	char	*b;

	b = buffer;
	width = argument->width;
	pre = argument->precision;
	sub = (pre > len) ? pre : len;
	if (PTF_FLAG_HASHTAG(argument->flags) && argument->precision >= 1)
		width -= 2;
	if (value == 0 && argument->precision == 0 && argument->width > 0)
		write_buffer(&buffer, ' ');
	if ((argument->is_negative == 1 || PTF_FLAG_PLUS(argument->flags)
				|| PTF_FLAG_SPACE(argument->flags)))
		width--;
	while (--width >= sub)
	{
		if (PTF_FLAG_ZERO(argument->flags) && !PTF_FLAG_MINUS(argument->flags))
			write_buffer(&buffer, '0');
		else
			write_buffer(&buffer, ' ');
	}
	*buffer = 0;
	return (ft_strlen(b));
}

static int	add_type(char *buffer)
{
	int i;

	i = 0;
	write_buffer(&buffer, '0');
	write_buffer(&buffer, 'x');
	i = 2;
	return (i);
}

int			ft_conv_pointeur(char *buffer, s_arg *argument, uintmax_t value)
{
	char	tmp[20];
	int		len;

	len = 0;
	ft_unsigned_itoa(value, tmp, 16, 20);
	argument->flags |= PTF_FLAG_HASHTAG(~0);
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (!PTF_FLAG_ZERO(argument->flags))
			len += add_width(&buffer[len], argument, ft_strlen(tmp), value);
		len += add_type(&buffer[len]);
		if (PTF_FLAG_ZERO(argument->flags))
			len += add_width(&buffer[len], argument, ft_strlen(tmp), value);
	}
	if (PTF_FLAG_MINUS(argument->flags))
		len += add_type(&buffer[len]);
	len += add_precision(&buffer[len], argument, tmp);
	if (PTF_FLAG_MINUS(argument->flags))
		len += add_width(&buffer[len], argument, ft_strlen(tmp), value);
	return (0);
}
