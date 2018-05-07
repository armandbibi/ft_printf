/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:24:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/07 20:44:07 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_conv_uint(char *buffer, unsigned int arg)
{
	ft_itoa(arg, buffer, 10);
	return (2);
}

int		ft_conv_int(char *buffer, int arg)
{
	ft_itoa(arg, buffer, 10);
	return (2);
}

int		ft_conv_hexa(char *buffer, int arg)
{
	ft_itoa(arg, buffer, 16);
	return (2);
}
