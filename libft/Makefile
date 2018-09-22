#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 17:46:38 by vkozhemi          #+#    #+#              #
#    Updated: 2018/04/04 18:46:21 by vkozhemi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
INCLUDE = libft.h
FLAGS = -Wall -Wextra -Werror

SRC =   ft_atoi.c \
        ft_bzero.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_itoa.c \
        ft_lstadd.c \
        ft_lstdel.c \
        ft_lstdelone.c \
        ft_lstiter.c \
        ft_lstmap.c \
        ft_lstnew.c \
        ft_memalloc.c \
        ft_memccpy.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memdel.c \
        ft_memmove.c \
        ft_memset.c \
        ft_putchar.c \
        ft_putchar_fd.c \
        ft_putendl.c \
        ft_putendl_fd.c \
        ft_putnbr.c \
        ft_putnbr_fd.c \
        ft_putstr.c \
        ft_putstr_fd.c \
        ft_range.c \
        ft_sqrt.c \
        ft_strcat.c \
        ft_strchr.c \
        ft_strclr.c \
        ft_strcmp.c \
        ft_strcpy.c \
        ft_strdel.c \
        ft_strdup.c \
        ft_strequ.c \
        ft_striter.c \
        ft_striteri.c \
        ft_strjoin.c \
        ft_strlcat.c \
        ft_strlen.c \
        ft_strmap.c \
        ft_strmapi.c \
        ft_strncat.c \
        ft_strncmp.c \
        ft_strncpy.c \
        ft_strnequ.c \
        ft_strnew.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_strsplit.c \
        ft_strstr.c \
        ft_strsub.c \
        ft_strtrim.c \
        ft_swap.c \
        ft_tolower.c \
        ft_toupper.c \
	ft_count_if.c \
	ft_foreach.c \
	get_next_line.c \


OBJECTS = $(SRC:.c=.o)
.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
		@echo made
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)

.c.o:
		@gcc -c $(FLAGS) -I $(INCLUDE) $(SRC) $<

.PHONY: clean
clean:
		@echo cleaned
		@/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
		@echo fcleaned
		@/bin/rm -f $(NAME)

.PHONY: re
re: fclean all