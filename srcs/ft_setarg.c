/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:04:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/07 20:39:58 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"../includes/ft_printf.h"



int		build_arg(const char *format, char *buffer, void *arg)
{
	int i;

	i = 2;
	format++;
	if (*format == 'c')
		*buffer = ((char)arg);
	if (*format == 's')
		ft_conv_string(buffer, (char*) arg);
	if (*format == 'd' || *format == 'i')
		ft_conv_int(buffer, (int)arg);
	if (*format == 'o')
		ft_conv_octal(buffer, (int)arg);
	if (*format == 'p')
		ft_conv_pointeur(buffer,(intmax_t)arg);
	if (*format == 'u')
		ft_conv_uint(buffer, (unsigned int) arg);
	if (*format == 'x')
		ft_conv_hexa(buffer, (int) arg);
	return i;
}
