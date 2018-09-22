#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 18:19:24 by vkozhemi          #+#    #+#              #
#    Updated: 2018/06/13 18:19:38 by vkozhemi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := fdf

INC_DIR := ./includes/
LIB_DIR := ./libft/
SRC_DIR := ./src/
OBJ_DIR := ./obj/

SRC := main.c validation.c alg_br.c create_window.c move.c key.c color.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS := -Wall -Wextra -Werror
GCC := gcc

FRMWR := -framework OpenGL -framework AppKit
MLX_LIB := -L /usr/local/lib/ -lmlx

LIBFT = $(LIB_DIR)libft.a
LIBFT_FLAGS := -L $(LIB_DIR) -lft
LIBFT_INC := $(LIB_DIR)incs
HDR_FLAGS := -I $(LIBFT_INC) -I $(INC_DIR) -I /usr/locale/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(GCC) $(OBJ) $(FLAGS) $(HDR_FLAGS) -o $(NAME) $(LIBFT) $(FRMWR) $(MLX_LIB)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(GCC) -c $< -o $@ $(FLAGS) $(HDR_FLAGS)

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean:
	make fclean -C $(LIB_DIR)
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all