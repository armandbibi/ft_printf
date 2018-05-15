/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:58:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/15 15:42:21 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_flag(const char *format, s_arg *argument)
{
	int i;

	argument->flags = 0;
	i = 0;
   	while(*format == '-' || *format == '+' ||*format == ' ' ||
		*format == '#' || *format == '0')
	{
		if (*format == '-')
			PTF_TURNON_FLAG(argument->flags, PTF_FLAG_MINUS(PTF_FLAG_ALL));
		if (*format == '+')
			PTF_TURNON_FLAG(argument->flags, PTF_FLAG_PLUS(PTF_FLAG_ALL));
		if (*format == '0')
			PTF_TURNON_FLAG(argument->flags, PTF_FLAG_ZERO(PTF_FLAG_ALL));
		if (*format == ' ')	
			PTF_TURNON_FLAG(argument->flags, PTF_FLAG_SPACE(PTF_FLAG_ALL));
		if (*format == '#')	
			PTF_TURNON_FLAG(argument->flags, PTF_FLAG_HASHTAG(PTF_FLAG_ALL));
		format++;
		i++;
	}
	return (i);
}

static int	get_width(const char *format, s_arg *argument)
{
	int i;

	i = 0;
	if ((i = atoi(format)) || *format == '0')
	{
		argument->width = i;
		if (i == 0)
			return (0);
		return (ft_log_discret(WIDTH, 10) + 1);
	}
	else
	{
		argument->width = 0;
		return (0);
	}
}

static int get_length_modifier(const char *format, s_arg *argument)
{
	int i;

	i = 0;
	while (*format == 'h' || *format == 'l' || *format == 'L' ||
			*format == 'q' || *format == 'j' || *format == 'z' ||
			*format == 't')
	{
		if (*format == 'j')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_J(PTF_FLAG_ALL));
		else if (*format == 'h' && *format+1 == 'h')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_HH(PTF_FLAG_ALL));
		else if (*format == 'h' && *format+1 != 'h')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_HH(PTF_FLAG_ALL));
		else if (*format == 'l' && *format + 1 != 'l')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_L(PTF_FLAG_ALL));
		else if (*format == 'l' && *format + 1 != 'l')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_LL(PTF_FLAG_ALL));
		else if (*format == 'z')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_Z(PTF_FLAG_ALL));
		i++;
		format++;
	}
	return (i);
}

static int	get_precision(const char *format, s_arg *argument)
{
	int i;

	i = 0;
	if (*format != '.')
	{
		argument->precision = 1;
		return (0);
	}
	format++;
	argument->precision = ft_atoi(format);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	return (i + 1);
}

static int	get_modifier(const char *format, s_arg *argument)
{
	if (*format == 's' || *format == 'S' || *format == 'p' ||
		*format == 'i' || *format == 'D' || *format == 'd' ||
		*format == 'o' || *format == 'O' || *format == 'u' ||
		*format == 'c' || *format == 'X' || *format == 'x' ||
		*format == 'C' || *format == '%' || *format == 'U')
	{
		argument->type = *format;
		if (*format  == 'D' || *format == 'U')
			PTF_TURNON_FLAG(argument->l_modifier, PTF_LEN_LL(PTF_FLAG_ALL));
		return (2);
	}
	else
	{
		argument->type = '\0';
		return (0);
	}
}

int			ft_parse_arg(const char *format, s_arg *argument)
{
	int index;
	argument->flags = 0;
	argument->l_modifier = 0;
	argument->is_negative = 0;
	format++;
	index = 0;
	index += get_flag(format, argument);
	index += get_width(&format[index], argument);	
	index += get_precision(&format[index], argument);
	index += get_length_modifier(&format[index], argument);
	index += get_modifier(&format[index], argument);
	return (index);
}
