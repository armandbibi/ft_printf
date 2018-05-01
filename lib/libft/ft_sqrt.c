/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:36:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/25 12:11:15 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int i)
{
	int racine;

	racine = 1;
	if (i < 0)
		racine = 0;
	while (racine * racine < i)
		racine++;
	if (racine * racine != i)
		racine = 0;
	return (racine);
}
