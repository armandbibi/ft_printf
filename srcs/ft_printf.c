/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:48:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/21 21:42:51 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int calc_tot(int src)
{
	if (src > 4194304)
		return (3);
	if (src > 1024)
		return (2);
	if (src > 127)
		return (1);
	return (0);
}

int		write_buffer(char **buffer, int src)
{
	static int	tot = 0;
	static int	buff_delimitor = 0;
	int			returned;
	if (buffer)
	{
		tot += calc_tot(src);
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
		{
			tot = 0;
			buff_delimitor = 0;
		}
		return (returned);
	}
	return (buff_delimitor + tot);
}

int		ft_printf(const char *format, ...)
{
	va_list		argl;
	char		buffer[BUFF_SIZE];
	int			i;
	char		*bufi;
	s_arg		argument;

	argument.len = 0;
	ft_strclr(buffer);
	i = 0;
	bufi = buffer;
	va_start(argl, format);
	while (*format)
	{
		if (*format != '%')
			write_buffer(&bufi, *format++);
		else
		{
			i = ft_parse_arg(format, &argument);
			if (build_arg(format, bufi, &argument, va_arg(argl, uintmax_t)) == -1)
				return (-1);
			bufi = &buffer[write_buffer(NULL, 0)];
			format = &format[i];
		}
	}
	write(1, buffer, write_buffer(NULL, 0));
	return (write_buffer(NULL, '0'));
}
