# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 13:01:09 by abiestro          #+#    #+#              #
#    Updated: 2018/05/21 15:46:59 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra

PATH_INCLUDES	= ./includes
PATH_SOURCES	= ./srcs
PATH_LIBS		= ./lib
PATH_OBJS		= ./objs

INCLUDES		= ft_printf.h 

ITEMS			= ft_printf \
				  parse_struct \
				  ft_setarg \
				  arg_char \
				  arg_wchar \
				  arg_octal \
				  arg_hexa \
				  arg_hashtag \
				  arg_string \
				  arg_pointeur \
				  arg_int \
				  arg_unsigned_int \
				  utils_math \
				  utils_unicode

LIBS			= libft


SRCS		= $(addprefix $(PATH_SOURCES)/,$(ITEMS:=.c))
OBJS		= $(addprefix $(PATH_OBJS)/, $(ITEMS:=.o))
INCLUDES	= $(addprefix $(PATH_INCLUDES)/, ft_printf.h)
LIB_OBJ 	= $(addprefix $(PATH_LIBS)/$(LIBS)/, $(pute))
salope		= $(shell cd $(PATH_LIBS)/$(LIBS) && make print_obj | grep -o '[a-z_]\{0,30\}\.o'| sed -e 's/^/lib\/libft\//' | tr '\n' ' ' )

all:$(NAME)

$(NAME):$(OBJS)
		cd $(PATH_LIBS)/$(LIBS) && $(MAKE)
		cp $(PATH_LIBS)/$(LIBS)/$(LIBS).h $(PATH_INCLUDES)
		ar -rcs $(NAME) $(OBJS) $(salope)

$(PATH_OBJS)/%.o : $(PATH_SOURCES)/%.c
	$(CC) -c $(CFLAGS)  $<  -o $@

get_lib_obj:
	@cd $(PATH_LIBS)/$(LIBS) && $(MAKE) print_obj | grep -o '[[a-z]*_]*[a-z]*\.o'| sed -e 's/^/libs\/libft\//' | tr '\n' ' '

clean:
	    cd $(PATH_LIBS)/$(LIBS) && $(MAKE) clean
		rm -f $(OBJS)

fclean: clean
	    cd $(LIBFTPASS) && rm -rf libft.a
		rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
