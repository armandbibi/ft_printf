/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:03:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/21 18:25:31 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <locale.h>
#include <wchar.h>
#include "includes/ft_printf.h"
int main()
{
	setlocale(LC_ALL, "");
	printf("%d\n",printf("%C", (wint_t) 536));
	printf("%d\n", ft_printf("%C",  (wint_t)536));
}
