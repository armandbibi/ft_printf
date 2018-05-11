/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:22:07 by abiestro          #+#    #+#             */
/*   Updated: 2018/05/10 19:45:06 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define BUFF_SIZE  750

/*
 * define flags on 1 integer
*/ 

# define PTF_TOGGLE_FLAG(x, flag)	(x ^= flag)
# define PTF_TURNON_FLAG(x, flag)	(x |= flag)
# define PTF_FLAG_MINUS(x)		(x & 0b0000001)
# define PTF_FLAG_PLUS(x)		(x & 0b0000010)
# define PTF_FLAG_ZERO(x)		(x & 0b0000100)
# define PTF_FLAG_SPACE(x)		(x & 0b0001000)
# define PTF_FLAG_HASHTAG(x)	(x & 0b0010000)
# define PTF_FLAG_ALL			(    0b1111111)

# define FLAG argument->flag
# define WIDTH argument->width
# define PRECISION argument->precision
# define TYPE argument->type
# define VALUE argument->value

typedef struct	t_arg
{
	int			flags;
	char		flag;
	int			flag_minus;
	int			flag_plus;
	int			flag_zero;
	int			flag_space;
	void		*value;
	int			width;
	char		type;
	int			precision;
}				s_arg;

int     		build_arg(const char *format, char *buffer,s_arg *argument, void *value);
int				ft_parse_arg(const char *format, s_arg *argument);
int				build_arg(const char *format, char *buffer, s_arg *argument, void *arg);
int				ft_printf(const char *format, ...);

int 			ft_conv_char(const char *format, char *buffer, s_arg *argument, char value);
int 			ft_conv_string(const char *format, char *buffer, s_arg *argument, char *value);
int     		ft_conv_octal(const char *format, char *buffer, s_arg *argument, int value);
int     		ft_conv_integer(const char *format, char *buffer, s_arg *argument, int value);
int     		ft_conv_hashtag(const char *format, char *buffer, s_arg *argument, int value);
int				ft_conv_hexa(const char *format, char *buffer, s_arg *argument, int  value);
int				ft_conv_pointeur(char *buffer, intmax_t arg);
int				ft_conv_uint(char *buffer, unsigned int arg);

int				ft_log_discret(unsigned int nb, int base);
#endif
