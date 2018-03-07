# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neprocur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/14 21:47:25 by neprocur          #+#    #+#              #
#    Updated: 2016/04/16 23:27:50 by neprocur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SYS := $(shell clang -dumpmachine)

CC			=	clang

NAME		=	fractol

LNAME		=	ft

DIR			=	lib$(LNAME)

HDR			=	$(DIR)/$(DIR).a

SRC			=	ft_fractol.c						\
				ft_pixel.c							\
				mandelbrot_julia.c					\
				ft_key_hook.c						\
				buddhabrot.c						\
				add.c								\
				anti.c								\
				tree.c								\

OBJ		=	$(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS		=	-L$(DIR) -l$(LNAME) -lm

CFLAGS1		=	-Wall -Werror -Wextra -Iincludes/ -I $(DIR)

OFLAGS		=	 -g

ifneq (, $(findstring linux, $(SYS)))
MLXFLAG		= -L/usr/local/lib/ -I/usr/local/include -lmlx -lXext -lX11
else
MLXFLAG		= -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
endif

CFLAGS		=	$(CFLAGS1) $(OFLAGS)

all:		$(HDR) $(NAME)

$(NAME):	$(OBJ) $(HDR)
		@echo "\033[34m------------------------------------------------"
		@echo "|    Création de l'exécutable en cours.       |"
		@echo "------------------------------------------------\033[0m"
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS) $(MLXFLAG)
		@echo "\n"

$(HDR):
		@echo "\033[34m---------------------------"
		@echo "|  Création de la libft.  |"
		@echo "---------------------------\033[0m"
		make -C $(DIR)
		@echo "\n"

clean:
		@echo "\033[34m-------------------------------"
		@echo "|  Suppression des binaires.  |"
		@echo "-------------------------------\033[0m"
		make -C $(DIR) clean
		rm -f $(OBJ)
		@echo "\n"

fclean:		clean
		@echo "\033[34m----------------------------------"
		@echo "|  Suppression des exécutables.  |"
		@echo "----------------------------------\033[0m"
		@make -C $(DIR) fclean
		rm -f $(NAME) $(HDR)
		@echo "\n"

re:			fclean all

.PHONY: all clean fclean re
