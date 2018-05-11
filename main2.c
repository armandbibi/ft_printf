/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:11:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/10 15:25:19 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# define ALL_ON		        	(0b1111)
# define TOGGLE(x, flag)		(x ^= flag)
# define IS_FLAG_A(x)   		(x & 0b0001)
# define IS_FLAG_B(x) 			(x & 0b0010)
# define IS_FLAG_C(x)   		(x & 0b0100)
# define IS_FLAG_D(x)  			(x & 0b1000)

int main(void)
{
	int flags = 0b0000;

	TOGGLE(flags, IS_FLAG_D(ALL_ON));
	TOGGLE(flags, (ALL_ON));

	if (IS_FLAG_A(flags))
		printf("flag is A\n");
	if (IS_FLAG_B(flags))
		printf("flag is B\n");
	if (IS_FLAG_C(flags))
		printf("flag is C\n");
	if (IS_FLAG_D(flags))
		printf("flag is D\n");
	int i = -1;
	if (i - (i ^= 0b1))
	printf("%d", i);
}


/*
# define TUTU(x, y)  (x.toot_##y)

typedef struct s_a
{
	int toot_a;
	int toot_b;
}				t_a;

int main()
{
	t_a tutu;

	tutu.toot_a = 42;
	tutu.toot_b = 12;
	TUTU(tutu, b) = 13;
	printf("%d, %d\n", tutu.toot_a, tutu.toot_b); 
}
*/
