/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:24:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/07 15:32:09 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_log_discret(int nb, int base)
{
	int i;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return i;
}
