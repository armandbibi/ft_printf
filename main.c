/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:03:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/28 19:35:31 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <locale.h>
#include <wchar.h>
#include "includes/ft_printf.h"
int main()
{
	setlocale(LC_ALL, "");
	printf("%4.1S you\n", L"Jambon");
	ft_printf("%4.1S mee\n", L"Jambon");
}

