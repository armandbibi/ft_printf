/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:58:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/08 19:10:29 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_flag(const char *format, s_arg *argument)
{
	if (*format == '-' || *format == '+' ||*format == ' ' ||
		*format == '#' || *format == '\0')
	{
		FLAG = *format;
		return 1;
	}
	else
	{
		FLAG = '0';
		return (0);
	}
}

static int	get_width(const char *format, s_arg *argument)
{
	int i;

	i = 0;
	if ((i = ft_atoi(format)) || *format == '0')
	{
		WIDTH = i;
		if (i == 0)
			return (0);
		return (ft_log_discret(WIDTH, 10) + 1);
	}
	else
	{
		WIDTH = 0;
		return (0);
	}
}

static int	get_precision(const char *format, s_arg *argument)
{
	if (*format != '.')
	{
		PRECISION = 1;
		return (0);
	}
	format++;
	PRECISION = ft_atoi(format);
	return (ft_log_discret(PRECISION, 10) + 2);
}

static int	get_modifier(const char *format, s_arg *argument)
{
	if (*format == 's' || *format == 'S' || *format == 'p' ||
		*format == 'i' || *format == 'D' || *format == 'd' ||
		*format == 'o' || *format == 'O' || *format == 'u' ||
		*format == 'c' || *format == 'X' || *format == 'x' ||
		*format == 'C')
	{
		TYPE = *format;
		return (2);
	}
	else
	{
		TYPE = '\0';
		return ('\0');
	}
}

int			ft_parse_arg(const char *format, s_arg *argument)
{
	int index;

	format++;
	index = 0;
	index = get_flag(format, argument);
	   format = &format[index];
	if (FLAG == '#')
		return (index);
	index += get_width(&format[index], argument);	
	index += get_precision(&format[index], argument);
	index += get_modifier(&format[index], argument);
	return (index);
}
