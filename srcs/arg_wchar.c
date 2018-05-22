/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:42:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/22 16:00:13 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static int stock_value(char **buffer, int value)
{
	if ((value >=  0xd800 && value <= 0xdfff) || (value >= 256 && MB_CUR_MAX !=4) || value < 0 || value > 0x10FFFF)
		return (-1);
	if (value > 0b1111111111111111)
	{
		write_buffer(buffer, (0b11110000 | (value >> 18)) & ~0b00001000);
		write_buffer(buffer, (0b10000000 | (value >> 12)) & ~0b01000000);
		write_buffer(buffer, (0b10000000 | (value >> 6)) & ~0b01000000);
		write_buffer(buffer, (0b10000000 | (value >> 0)) & ~0b01000000);
	}
	else if (value > 0b11111111111)
	{
		write_buffer(buffer, (0b11100000 | (value >> 12)) & ~0b00010000);
		write_buffer(buffer, (0b10000000 | (value >> 6)) & ~0b01000000);
		write_buffer(buffer, (0b10000000 | (value >> 0)) & ~0b01000000);
	}
	else if (value > 0b1111111)
	{
		write_buffer(buffer, (0b11000000 | (value >> 6)) & ~0b00100000);
		write_buffer(buffer, (0b10000000 | (value >> 0)) & ~0b01000000);
	}
	else
		write_buffer(buffer, value);
}

static int calc_width(s_arg *a, int value)
{
	if (value > 0xff)
		a->width--;
	if (value > 0xfff)
		a->width--;
	if (value > 0xffff)
		a->width--;

}

int ft_conv_wchar(char *buffer, s_arg *argument, int value)
{
	char *b = buffer;
	if (PTF_FLAG_MINUS(argument->flags))
		if(stock_value(&buffer, value) == -1)
			return (-1);
	calc_width(argument, value);	
	while (argument->width-- > 1)
		write_buffer(&buffer, ' ');
	if (!PTF_FLAG_MINUS(argument->flags))
		if(stock_value(&buffer, value) == -1)
			return (-1);
	return (0);
}
