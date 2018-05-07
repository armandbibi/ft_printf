/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_pointeur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:23:53 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/07 20:18:15 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv_pointeur(char *buffer, intmax_t arg)
{
	ft_strcpy(buffer, "0x");
	buffer = &buffer[2];
	ft_itoa(arg, buffer, 16);
	return (2);
}
