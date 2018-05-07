/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:22:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/07 20:42:29 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define BUFF_SIZE  750
# define STRING 's'
# define INT 'i'

typedef struct	t_arg
{
	char		type;
	void		*value;
}				s_arg;

int				build_arg(const char *format, char *buffer, void *arg);
int				ft_printf(const char *format, ...);

int				ft_conv_string(char *buffer, char *arg);
int				ft_conv_octal(char *buffer, int arg);
int				ft_conv_pointeur(char *buffer, intmax_t arg);
int				ft_conv_uint(char *buffer, unsigned int arg);
int				ft_conv_int(char *buffer, int arg);
int				ft_conv_hexa(char *buffer, int arg);

int				ft_log_discret(int nb, int base);
#endif
