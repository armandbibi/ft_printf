/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:04:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/09 23:30:39 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"../includes/ft_printf.h"



int		build_arg(const char *format, char *buffer,s_arg *argument, void *value)
{
	if (TYPE == 'c' || TYPE == 'C')
		ft_conv_char(format, buffer, argument, (char)value);
	if (TYPE == 's' || TYPE == 'S')
		ft_conv_string(format, buffer, argument, (char *)value);
	if (TYPE == 'i' || TYPE == 'D' || TYPE == 'd')
		ft_conv_integer(format, buffer, argument, (int)value);
	if (TYPE == 'o' || TYPE == 'O')
		ft_conv_octal(format, buffer, argument, (int)value);
	if (argument->type == '%')
		ft_conv_hashtag(format, buffer, argument, (int)value);
	if (argument->type == 'x' || argument->type == 'X')
		ft_conv_hexa(format, buffer, argument, (int)value);
/*    if (TYPE == 'x' || TYPE == 'X')
		ft_conv_hexa_decimal(format, buffer, argument, (int)value);
    if (TYPE == 'p')
		ft_conv_pointeur(format, buffer, argument, (int)value);
	if (TYPE == 'u' || type == 'U')
		ft_conv_unsigned_int(format, buffer, argument, (int)value);*/
	return 0;
}
