# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykohda <ykohda@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 09:13:34 by ykohda            #+#    #+#              #
#    Updated: 2021/07/04 15:42:54 by ykohda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make --no-print-directory
NAME = miniRT
NAME_B = miniRT_b
CMP = gcc
FLAG = -Wall -Werror -Wextra -D BUFFER_SIZE=200
MLXFLAG = -lm -L./minilibx-linux/ -lmlx -lXext -lX11 -L./libft/ -lft
INC = -I ./includes/ -I ./input/ -I ./libft/ -I ./input/gnl/
INC_B = -I ./bonus/includes/ -I ./bonus/input/ -I ./bonus/libft/ \
	-I ./bonus/input/gnl/
FILE =	input/check2.c \
	input/check.c \
	input/check_util2.c \
	input/check_util.c \
	input/hook.c \
	input/input_main.c \
	input/set2.c \
	input/set3.c \
	input/set.c \
	input/set_utils.c \
	input/gnl/get_next_line.c \
	input/gnl/get_next_line_utils.c \
	srcs/color.c \
	srcs/create_screen.c \
	srcs/cylinder.c \
	srcs/malloc_free.c \
	srcs/phong2.c \
	srcs/phong.c \
	srcs/solve_method.c \
	srcs/vector_calc2.c \
	srcs/cone.c \
	srcs/create_world.c \
	srcs/malloc_free2.c \
	srcs/obj_cross_detection.c \
	srcs/phong3.c \
	srcs/plane.c \
	srcs/sphere.c \
	srcs/vector_calc.c \
	main.c
SRCS = $(FILE:%.c=./%.c)
SRCS_B = $(FILE:%.c=./bonus/%_bonus.c)
OBJ = $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)
LIBDIR = ./libft/

all: $(NAME)

bonus: $(NAME_B)

.c.o:
	$(CMP) $(FLAG) $(INC) $(MLXFLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
		$(MAKE) -C $(LIBDIR)
		$(CMP) $^ $(FLAG) $(INC) $(MLXFLAG) -o $@

$(NAME_B): $(OBJ_B)
		$(MAKE) -C $(LIBDIR)
		$(CMP) $^ $(FLAG) $(INC_B) $(MLXFLAG) -o $@

clean:
		$(MAKE) clean -C $(LIBDIR)
		rm -rf $(OBJ) $(OBJ_B)

fclean: clean
		$(MAKE) fclean -C $(LIBDIR)
		rm -rf $(NAME) $(NAME_B)

re : fclean all

.PHONY: all clean fclean re bonus
