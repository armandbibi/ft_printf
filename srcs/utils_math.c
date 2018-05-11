/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:24:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/10 17:44:42 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_log_discret(unsigned int nb, int base)
{
	int i;
	i = 0;
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return i;
}
