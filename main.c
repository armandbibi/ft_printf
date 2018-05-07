/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:23:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/07 20:43:22 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(int ac, char **av)
{
	int a = 4;

	ft_printf("ft_printf: voici un charactere : --- %c ---\n", 'a');
	printf("   printf: voici un charactere : --- %c ---\n", 'a');
	ft_printf("ft_printf: voici une chaine : --- %s ---\n", "chaine");
	printf("   printf: voici une chaine : --- %s ---\n", "chaine");
	ft_printf("ft_printf:  voici un 253 : --- %d ---\n", 253);
	printf("   printf:  voici un 253 : --- %d ---\n", 253);	
	ft_printf("ft_printf:  voici l'octal de 253 : --- %o ---\n", 253);
	printf("   printf:  voici l'octal de 253 : --- %o ---\n", 253);
	ft_printf("ft_printf:  voici le pointeur de a: --- %p ---\n", &a);
	printf("   printf:  voici le pointeur de a: --- %p ---\n", &a);
	ft_printf("ft_printf:  voici le int de -223: --- %d ---\n", -223);
	printf("   printf:  voici le int de -223: --- %d ---\n", -223);
	ft_printf("ft_printf:  voici l'unsigned int de 28: --- %u ---\n", 28);
	printf("   printf:  voici l'unsigned int de 28: --- %u ---\n", 28);
	ft_printf("ft_printf:  voici l'hexa de 28: --- %x ---\n", 28);
	printf("   printf:  voici l'hexa de 28: --- %x ---\n", 28);

}
