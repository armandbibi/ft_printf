/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 14:04:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/28 19:56:00 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		build_arg(const char *format, char *buffer,
		s_arg *argument, uintmax_t *value)
{
	if (argument->type == 'c' && !PTF_LEN_L(argument->l_modifier))
		ft_conv_char(buffer, argument, (char)value);
	if (argument->type == 'C')
		if (ft_conv_wchar(buffer, argument, (int)value) == -1)
			return (-1);
	if (TYPE == 's' && TYPE != 'S')
		ft_conv_string(format, buffer, argument, (char *)value);
	if (TYPE == 'S')
		return (ft_conv_wstring(buffer, argument, (char *)value));
	if (TYPE == 'i' || TYPE == 'D' || TYPE == 'd')
		ft_conv_integer(buffer, argument, (intmax_t)value);
	if (TYPE == 'o' || TYPE == 'O')
		ft_conv_octal(buffer, argument, (uintmax_t)value);
	if (argument->type == '%')
		ft_conv_hashtag(format, buffer, argument, (int)value);
	if (argument->type == 'x' || argument->type == 'X')
		ft_conv_hexa(buffer, argument, (uintmax_t)value);
	if (argument->type == 'p')
		ft_conv_pointeur(buffer, argument, (uintmax_t)value);
	if (argument->type == 'u' || argument->type == 'U')
		ft_conv_unsigned_integer(buffer, argument, (uintmax_t)value);
	return (0);
}
