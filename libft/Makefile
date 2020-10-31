# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: memelia <memelia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 18:14:41 by memelia           #+#    #+#              #
#    Updated: 2020/01/10 18:48:43 by memelia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a

MAKE_DIR = ./Makefiles/
OBJ_PATH = ./objects/
OBJ_ERROR_PATH = ./objects/error/*
OBJ_IO_PATH = ./objects/io/*
OBJ_MEMORY_PATH = ./objects/memory/*
OBJ_SORT_PATH = ./objects/sort/*
OBJ_STRING_PATH = ./objects/string/*
OBJ_VECTOR_PATH = ./objects/vector/*

OBJ = $(OBJ_ERROR_PATH) $(OBJ_IO_PATH) $(OBJ_MEMORY_PATH) $(OBJ_SORT_PATH) $(OBJ_STRING_PATH) $(OBJ_VECTOR_PATH)

all: $(NAME)

$(NAME):
	@make -f $(MAKE_DIR)error.mk
	@make -f $(MAKE_DIR)io.mk
	@make -f $(MAKE_DIR)memory.mk
	@make -f $(MAKE_DIR)sort.mk
	@make -f $(MAKE_DIR)string.mk
	@make -f $(MAKE_DIR)vector.mk
	@ar -rc $(NAME) $(OBJ) $?
	@ranlib $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader

clean: 
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
