/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:48:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/28 21:12:39 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				write_buffer(char **buffer, int src)
{
	static int	buff_delimitor = 0;
	int			returned;

	if (buffer)
	{
		**buffer = src;
		buff_delimitor++;
		if (buff_delimitor > 0 && buff_delimitor % BUFF_SIZE == 0)
		{
			write(1, buffer, BUFF_SIZE);
			*buffer = buffer[-BUFF_SIZE];
		}
		else
			++*buffer;
	}
	if (!buffer)
	{
		returned = buff_delimitor;
		if (src == '0')
			buff_delimitor = 0;
		return (returned);
	}
	return (buff_delimitor);
}

static int		add_nomodifier(char **bufi, s_arg *argument)
{
	int i;

	i = 1;
	if (argument->flags)
		i++;
	if (argument->width > 0)
	{
		i += ft_log_discret(argument->width, 10) + 1;
		while (--argument->width > 0)
		{
			if (PTF_FLAG_ZERO(argument->flags))
				write_buffer(bufi, '0');
			else
				write_buffer(bufi, ' ');
		}
		if (!PTF_NO_PRE(argument->l_modifier))
			i++;
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list		argl;
	char		buffer[BUFF_SIZE];
	int			i;
	int			k;
	char		*bufi;
	s_arg		argument;

	argument.len = 0;
	i = 0;
	bufi = buffer;
	ft_bzero(&buffer, BUFF_SIZE);
	va_start(argl, format);
	k = 0;
	while (*format)
	{
		k++;
		if (*format != '%')
			write_buffer(&bufi, *format++);
		else
		{
			i = ft_parse_arg(format, &argument);
			if (argument.type == 0)
				format = &format[add_nomodifier(&bufi, &argument)];
			else if (argument.type == '%')
				build_arg(format, bufi, &argument, 0);
			else if (build_arg(format, bufi, &argument, va_arg(argl, uintmax_t)) < 0)
			{
				write(1, buffer, write_buffer(NULL, '0') - k + 1);
				return (-1);
			}
			bufi = &buffer[write_buffer(NULL, 0) % BUFF_SIZE];
			format = &format[i];
			k = 0;
		}
	}
	va_end(argl);
	write(1, buffer, write_buffer(NULL, 0));
	return (write_buffer(NULL, '0'));
}
