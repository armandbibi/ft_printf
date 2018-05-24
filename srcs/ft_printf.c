/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:48:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/24 21:33:10 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_buffer(char **buffer, int src)
{
	static int	tot = 0;
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
		{
			tot = 0;
			buff_delimitor = 0;
		}
		return (returned);
	}
	return (buff_delimitor);
}

int		ft_printf(const char *format, ...)
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
	ft_strclr(buffer);
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
			if (build_arg(format, bufi, &argument, va_arg(argl, uintmax_t)) >= 0)
			{
				k = 0;
				bufi = &buffer[write_buffer(NULL, 0) % BUFF_SIZE];
				format = &format[i];
			}
			else
			{
				write(1, buffer, write_buffer(NULL, '0') - k + 1);
				return (-1);
			}
		}
	}
	write(1, buffer, write_buffer(NULL, 0));
	return (write_buffer(NULL, '0'));
}
