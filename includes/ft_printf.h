/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:22:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/19 15:04:41 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define BUFF_SIZE  750
# define PTF_FLAG_ALL			(    0b111111111111)
# define PTF_TOGGLE_FLAG(x, flag)	(x ^= flag)
# define PTF_TURNON_FLAG(x, flag)	(x |= flag)

/*
 *** define flags on 1 integer
*/
# define PTF_FLAG_MINUS(x)		(x & 0b0000001)
# define PTF_FLAG_PLUS(x)		(x & 0b0000010)
# define PTF_FLAG_ZERO(x)		(x & 0b0000100)
# define PTF_FLAG_SPACE(x)		(x & 0b0001000)
# define PTF_FLAG_HASHTAG(x)	(x & 0b0010000)

/*
 *** define length modifier on 1 int
*/
# define PTF_LEN_H(x)		(x & 0b00000001)
# define PTF_LEN_HH(x)		(x & 0b00000010)
# define PTF_LEN_L(x)		(x & 0b00000100)
# define PTF_LEN_LL(x)		(x & 0b00001000)
# define PTF_LEN_J(x)		(x & 0b00010000)
# define PTF_LEN_Z(x)		(x & 0b00100000)
# define FLAG argument->flag
# define WIDTH argument->width
# define PRECISION argument->precision
# define TYPE argument->type
# define VALUE argument->value

typedef struct	t_arg
{
	int			flags;
	int			l_modifier;
	int			is_negative;
	int			width;
	char		type;
	int			precision;
}				s_arg;

int				ft_parse_arg(const char *format, s_arg *argument);
int				build_arg(const char *format, char *buffer,
		s_arg *argument, uintmax_t *arg);
int				write_buffer(char *buffer, char *src, int len);
int				ft_printf(const char *format, ...);
int				ft_conv_char(const char *format, char *buffer,
		s_arg *argument, char value);
int				ft_conv_string(const char *format, char *buffer,
		s_arg *argument, char *value);
int				ft_conv_octal(char *buffer, s_arg *argument, uintmax_t value);
int				ft_conv_integer(char *buffer, s_arg *argument, intmax_t value);
int				ft_conv_unsigned_integer(char *buffer, s_arg *argument,
		uintmax_t value);
int				ft_conv_hashtag(const char *format, char *buffer,
		s_arg *argument, int value);
int				ft_conv_hexa(char *buffer, s_arg *argument, uintmax_t value);
int				ft_conv_pointeur(char *buffer, s_arg *argument,
		uintmax_t value);
int				ft_conv_uint(char *buffer, unsigned int arg);
int				ft_log_discret(unsigned int nb, int base);
int				ft_cast_itoa(intmax_t value, char *t, s_arg *arg, int base);
int				ft_cast_uitoa(uintmax_t value, char *t, s_arg *arg, int base);
#endif
