/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:48:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/10 17:50:09 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void print_composants(s_arg argument)
{

	printf("\n\n\nargument flag     = *** %c ***\n", argument.flag);
	printf("argument flags     = *** %d ***\n", argument.flags);
	printf("argument width     = *** %d ***\n", argument.width);
	printf("argument modifier  = *** %c ***\n", argument.type);
	printf("argument precision = *** %d ***\n\n\n", argument.precision);
}


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
//print_composants(argument);
			build_arg(format, bufi, &argument, va_arg(argl, void*));
			while (*bufi)
				bufi++;
			format = &format[i];
		}
	}
	*bufi = '\0';
	write (1, buffer, ft_strlen(buffer));
	return (ft_strlen(buffer));
}
