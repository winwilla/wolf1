# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memelia <memelia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 13:17:22 by memelia           #+#    #+#              #
#    Updated: 2020/01/10 15:42:35 by memelia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_VECTOR_PATH = ./source/vector/
OBJ_VECTOR_PATH = ./objects/vector/
INC_PATH = ./includes/
SRC_VECTOR = $(addprefix $(SRC_VECTOR_PATH), $(SRC_VECTOR_NAME))
OBJ_VECTOR = $(addprefix $(OBJ_VECTOR_PATH), $(OBJ_VECTOR_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_VECTOR_NAME =	ft_vec_distance.c				ft_vec_dot.c 		ft_vec_length.c 	ft_vec_multiplication.c	\
					ft_vec_multiplication_num.c 	ft_vec_subtract.c	ft_vec_sum.c		ft_vec_init.c

OBJ_VECTOR_NAME = $(SRC_VECTOR_NAME:.c=.o)

all: $(NAME)

$(OBJ_VECTOR_PATH)%.o: $(SRC_VECTOR_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_vector.h
	@mkdir -p $(OBJ_VECTOR_PATH)
	@gcc $(INC) -o $@ -c $<

$(NAME): $(OBJ_VECTOR)

re: all
