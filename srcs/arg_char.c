/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:53:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/21 15:47:25 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_char(char *buffer, s_arg *argument, char value)
{
	if (PTF_FLAG_MINUS(argument->flags))
		write_buffer(&buffer, value);
	while (argument->width-- > 1)
		write_buffer(&buffer, ' ');
	if (!PTF_FLAG_MINUS(argument->flags))
		write_buffer(&buffer, value);
	return (0);
}
