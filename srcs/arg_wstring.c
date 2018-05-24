/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:28:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/24 21:42:59 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	add_width(char **buffer, s_arg *argument, int *value)
{
	char *b;
	int t;
	int total;

	t = 0;
	total = 0;
	while (value[t] != 0)
	{
		if (t >0b11111111 )
			total++;
		if (t > 0b11111111111)
			total++;
		if (t >  0b1111111111111111)
			total++;
		t++;
	}
	b = *buffer;
	if (!PTF_FLAG_MINUS(argument->flags))
	{
		if (argument->precision != 1 &&
				argument->precision <= total)
			argument->width -= argument->precision;
		else
			argument->width -= total;
	}
	else
		argument->width -= total;
	while (argument->width-- > 0)
		write_buffer(buffer, ' ');
	return (ft_strlen(b));
}

int			ft_conv_wstring(char *buffer, s_arg *argument, int *value)
{
	int		*b;
	int		c[8];
	char 	*saved;
	int		tot;

	if (value == NULL)
		value = c;
	b = value;
	saved = buffer;
	tot = -1;
	if (!PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, b);
	if (argument->precision == 1)
	{
		while (*value)
			if (stock_value(&buffer, *value++) == -1)
				return tot;
	}
	else
		while (argument->precision-- > 0 && *value)
			if(stock_value(&buffer, *value++) == -1)
				return (-1);
	if (PTF_FLAG_MINUS(argument->flags))
		add_width(&buffer, argument, saved);
}
