/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:24:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/15 16:12:18 by abiestro         ###   ########.fr       */
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

int     ft_cast_uitoa(uintmax_t value, char *tmp, s_arg *arg, int base)
{
	if (PTF_LEN_J(arg->l_modifier))
		ft_unsigned_itoa((uintmax_t)value, tmp, base, 20); 
	else if (PTF_LEN_LL(arg->l_modifier))
		ft_unsigned_itoa((unsigned long long)value, tmp, base, 20); 
	else if (PTF_LEN_L(arg->l_modifier))
		ft_unsigned_itoa((unsigned long)value, tmp, base, 20);
	else if (PTF_LEN_Z(arg->l_modifier))
		ft_unsigned_itoa((size_t)value, tmp, base, 20);
	else if (PTF_LEN_H(arg->l_modifier))
		ft_unsigned_itoa((unsigned short)value, tmp, base, 20);
	else if (PTF_LEN_HH(arg->l_modifier))
		ft_unsigned_itoa((unsigned char)value, tmp, base, 20);
	else
		ft_unsigned_itoa((unsigned int)value, tmp, base, 20);
}

int		ft_cast_itoa(intmax_t value, char *tmp, s_arg *arg, int base)
{
	if (PTF_LEN_J(arg->l_modifier) && (intmax_t)value < 0)
	{
		arg->is_negative = 1;
		ft_unsigned_itoa((intmax_t)-value, tmp, base, 20);
	}
	else if (PTF_LEN_J(arg->l_modifier) && (intmax_t)value > 0)
		ft_unsigned_itoa((intmax_t)value, tmp, base, 20);
	else if (PTF_LEN_LL(arg->l_modifier) && (long long)value < 0)
	{
		arg->is_negative = 1;
		ft_unsigned_itoa((long long)-value, tmp, base, 20);
	}
	else if (PTF_LEN_LL(arg->l_modifier))
		ft_unsigned_itoa((long long)value, tmp, base, 20);
	else if ((PTF_LEN_L(arg->l_modifier)) && (long)value < 0)
	{
		ft_unsigned_itoa((long)-value, tmp, base, 20);
		arg->is_negative = 1;
	}
	else if ((PTF_LEN_L(arg->l_modifier)) && (long)value > 0)
		ft_unsigned_itoa((long)value, tmp, base, 20);
	else if (PTF_LEN_Z(arg->l_modifier))
		ft_unsigned_itoa((size_t)value, tmp, base, 20);
	else if (PTF_LEN_H(arg->l_modifier) && (short)value < 0)
	{	
		arg->is_negative = 1;
		ft_unsigned_itoa((short)-value, tmp, base, 6);
	}
	else if (PTF_LEN_H(arg->l_modifier) && (short)value > 0)
		ft_unsigned_itoa((short)value, tmp, base, 6);
	else if (PTF_LEN_HH(arg->l_modifier) && (char)value < 0)
	{
		arg->is_negative = 1;
		ft_unsigned_itoa((char)-value, tmp, base, 4);
	}
	else if (PTF_LEN_HH(arg->l_modifier) && (char)value > 0 )
		ft_unsigned_itoa((char)value, tmp, base, 4);
	else if ((int)value < 0)
	{
		ft_unsigned_itoa(-(int)value, tmp, base, 10);
		arg->is_negative = 1;
	}
	else
		ft_unsigned_itoa((int)value, tmp, base, 10);
}
