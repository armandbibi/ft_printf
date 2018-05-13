/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:23:56 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/12 19:28:46 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(int ac, char **av)
{
	int a = 4;

	printf("******SOME CHAR CONVERTIONS********\n");

	ft_printf("ft_printf: voici un charactere c *** a : --- %c ---\n", 'a');
	printf("   printf: voici un charactere c *** a : --- %c ---\n\n", 'a');

	ft_printf("ft_printf: voici un charactere .10c *** a : --- %.10c ---\n", 'a');
	printf("   printf: voici un charactere .10c *** a : --- %.10c ---\n\n", 'a');

	ft_printf("ft_printf: voici un charactere 10c *** a : --- %10c ---\n", 'a');
	printf("   printf: voici un charactere 10c *** a : --- %10c ---\n\n", 'a');

	ft_printf("ft_printf: voici un charactere -10c *** a : --- %-10c ---\n", 'a');
	printf("   printf: voici un charactere -10c *** a : --- %-10c ---\n\n", 'a');
	
	printf("******SOME STRING CONVERTIONS ********\n");

	ft_printf("ft_printf: voici une s *** 'chaine' : --- %s ---\n", "chaine");
	printf("   printf: voici une s *** 'chaine' : --- %s ---\n\n", "chaine");

	ft_printf("ft_printf: voici une 10s *** 'chaine' : --- %10s ---\n", "chaine");
	printf("   printf: voici une 10s *** 'chaine' : --- %10s ---\n\n", "chaine");

	ft_printf("ft_printf: voici une .10s *** 'chaine' : --- %.10s ---\n", "chaine");
	printf("   printf: voici une .10s *** 'chaine' : --- %.10s ---\n\n", "chaine");

	ft_printf("ft_printf: voici une 10.10s *** 'chaine' : --- %10.10s ---\n", "chaine");
	printf("   printf: voici une 10.10s *** 'chaine' : --- %10.10s ---\n\n", "chaine");

	ft_printf("ft_printf: voici une -10.10s *** 'chaine' : --- %-10.10s ---\n", "chaine");
	printf("   printf: voici une -10.10s *** 'chaine' : --- %-10.10s ---\n\n", "chaine");

	ft_printf("ft_printf: voici une +1.10s *** 'chaine' : --- %+1.10s ---\n", "chaine");
	printf("   printf: voici une +1.10s *** 'chaine' : --- %-1.10s ---\n\n", "chaine");

	printf("******SOME INTEGER CONVERTIONS ********\n");

	ft_printf("ft_printf:  voici un 253 : --- %d ---\n", 253);
	printf("   printf:  voici un 253 : --- %d ---\n\n", 253);	

	ft_printf("ft_printf:  voici un -253 : --- %d ---\n", -253);
	printf("   printf:  voici un -253 : --- %d ---\n\n", -253);	

	ft_printf("ft_printf:  voici un 53 avec .1d : --- %.1d ---\n", 53);
	printf("   printf:  voici un 53 avec .1d : --- %.1d ---\n\n", 53);	

	ft_printf("ft_printf:  voici un 53 avec .10d : --- %.10d ---\n", 53);
	printf("   printf:  voici un 53 avec .10d : --- %.10d ---\n\n", 53);
	ft_printf("ft_printf:  voici un 53 avec ' '.10d : --- % .10d ---\n", 53);
	printf("   printf:  voici un 53 avec ' '.10d : --- % .10d ---\n\n", 53);
	ft_printf("ft_printf:  voici l'octal de 253 : --- %o ---\n", 253);
	printf("   printf:  voici l'octal de 253 : --- %o ---\n\n", 253);
	ft_printf("ft_printf:  voici le pointeur de a: --- %p ---\n", &a);
	printf("   printf:  voici le pointeur de a: --- %p ---\n\n", &a);
	ft_printf("ft_printf:  voici le int de -223: --- %d ---\n", -223);
	printf("   printf:  voici le int de -223: --- %d ---\n\n", -223);
	ft_printf("ft_printf:  voici l'unsigned int de 28: --- %u ---\n", 28);
	printf("   printf:  voici l'unsigned int de 28: --- %u ---\n\n", 28);
	ft_printf("ft_printf:  voici l'hexa de 28: --- %x ---\n", 28);
	printf("   printf:  voici l'hexa de 28: --- %x ---\n\n", 28);

	ft_printf("ft_printf: int with precision : -10.10d de 125 : --- %-10.10d ---\n", 125);
	printf("   printf: int with precision : -10.10d de 125 : --- %-10.10d ---\n\n", 125);

	ft_printf("ft_printf: int with precision : 10.10d de 125 : --- %10.10d ---\n", 125);
	printf("   printf: int with precision : 10.10d de 125 : --- %10.10d ---\n\n", 125);

	ft_printf("ft_printf: int with precision : .10d de 125 : --- %.10d ---\n", 125);
	printf("   printf: int with precision : .10d de 125 : --- %.10d ---\n\n", 125);

	ft_printf("ft_printf: int : 10d de 125 : --- %10d ---\n", 125);
	printf("   printf: int : 10d de 125 : --- %10d ---\n\n", 125);

}
