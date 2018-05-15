/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:48:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/15 14:00:12 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list argl;
	char buffer[BUFF_SIZE];
	int i;
	char *bufi;
	s_arg	argument;

	ft_strclr(buffer);
	i = 0;
	bufi = buffer;
	va_start(argl, format);
	while (*format)
	{
		if (*format != '%')
		{
			*bufi = *format;
			bufi++;
			format++;
		}
		else
		{
			i = ft_parse_arg(format, &argument);
			build_arg(format, bufi, &argument, va_arg(argl, uintmax_t));
			while (*bufi)
				bufi++;
			format = &format[i];
		}
	}
	*bufi = '\0';
	write (1, buffer, ft_strlen(buffer));
	return (ft_strlen(buffer));
}
