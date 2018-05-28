/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:42:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/28 19:55:19 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				stock_value(char **buffer, int value)
{
	if ((value >= 0xd800 && value <= 0xdfff) ||
			(value > 255 && MB_CUR_MAX == 1) || value < 0 || value > 0x10FFFF)
		return (-1);
	if (value > 0xFFFF)
	{
		write_buffer(buffer, (0b11110000 | (value >> 18)) & ~0b00001000);
		write_buffer(buffer, (0b10000000 | (value >> 12)) & ~0b01000000);
		write_buffer(buffer, (0b10000000 | (value >> 6)) & ~0b01000000);
		write_buffer(buffer, (0b10000000 | (value >> 0)) & ~0b01000000);
		return (3);
	}
	else if (value > 0x7FF)
	{
		write_buffer(buffer, (0b11100000 | (value >> 12)) & ~0b00010000);
		write_buffer(buffer, (0b10000000 | (value >> 6)) & ~0b01000000);
		write_buffer(buffer, (0b10000000 | (value >> 0)) & ~0b01000000);
		return (2);
	}
	else if ((value > 0x7F && MB_CUR_MAX != 1) || value > 255)
	{
		write_buffer(buffer, (0b11000000 | (value >> 6)) & ~0b00100000);
		write_buffer(buffer, (0b10000000 | (value >> 0)) & ~0b01000000);
		return (1);
	}
	else
	{
		write_buffer(buffer, value);
		return (0);
	}
}

static int		calc_width(s_arg *a, int value)
{
	if ((value > 0x7F && MB_CUR_MAX != 1) || value > 255)
		a->width--;
	if (value > 0x7FF)
		a->width--;
	if (value > 0xFFFF)
		a->width--;
	return (0);
}

int				ft_conv_wchar(char *buffer, s_arg *argument, int value)
{
	char *b;

	if ((value >= 0xd800 && value <= 0xdfff) ||
			(value > 255 && MB_CUR_MAX == 1) || value < 0 || value > 0x10FFFF)
		return (-1);
	b = buffer;
	if (PTF_FLAG_MINUS(argument->flags))
		stock_value(&buffer, value);
	calc_width(argument, value);
	while (argument->width-- > 1)
	{
		if (PTF_FLAG_ZERO(argument->flags))
			write_buffer(&buffer, '0');
		else
			write_buffer(&buffer, ' ');
	}
	if (!PTF_FLAG_MINUS(argument->flags))
		stock_value(&buffer, value);
	return (0);
}
