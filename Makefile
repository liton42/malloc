# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/02 18:16:06 by zadrien           #+#    #+#              #
#    Updated: 2020/08/20 11:20:46 by liton            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean name re

CC = gcc
SNAME = malloc
LIBNAME = libft_malloc
CFLAGS = #-g -Wall -Werror -Wextra
CPATH = srcs/
OPATH = obj/
HPATH = includes/ libft/
INC = $(addprefix -I , $(HPATH))
SFILES= calloc.c \
		free.c \
		malloc.c \
		realloc.c \
		show_mem.c \

OSFILES= $(SFILES:.c=.o)

ifeq ($(HOSTTYPE),) # search for hosttype env variabl
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif


LIBFILES = calloc.c \
		free.c \
		malloc.c \
		realloc.c \
		show_mem.c \

OLIBFILES = $(LIBFILES:.c=.o)
LIBOBJ = $(addprefix $(OPATH), $(OLIBFILES))


HFILES= includes/malloc.h \
		libft/libft.h	\

SOBJ= $(addprefix $(OPATH), $(OSFILES))

all: $(LIBNAME)

$(LIBNAME): $(LIBOBJ)
	make -C libft
	$(CC) $(CFLAGS) libft/libft.a $(LIBOBJ) -shared -o $(LIBNAME)_$(HOSTTYPE).so
	ln -s $(LIBNAME)_$(HOSTTYPE).so $(LIBNAME).so

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
	@mkdir -p $(OPATH)
	$(CC) $(CFLAGS) $(INC) $< -c -o $@

clean:
	make -C libft clean
	rm -rf $(SOBJ)


fclean: clean
	make -C libft fclean
	rm -rf $(SNAME)
	rm -rf $(OPATH)
	rm -rf $(LIBNAME)_$(HOSTTYPE).so
	rm -rf $(LIBNAME).so

re: fclean all

norme:
		@norminette srcs/**/**.[ch]
		@norminette libft/*.[ch]
