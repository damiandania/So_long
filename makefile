# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 18:19:17 by ddania-c          #+#    #+#              #
#    Updated: 2023/05/05 14:51:36 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~NAME~~~~~
NAME = so_long

#~~~~~~SOURCES~~~~~~
SRC_DIR = ./src
SRCS = $(SRC_DIR)/main.c\
			$(SRC_DIR)/get_next_line.c \
			$(SRC_DIR)/get_next_line_utils.c \
			$(SRC_DIR)/01_map_create.c \
			$(SRC_DIR)/02_data_init.c \
			$(SRC_DIR)/03_map_check.c \
			$(SRC_DIR)/04_win_init.c \
			$(SRC_DIR)/05_img_init.c \
			$(SRC_DIR)/06_render.c \
			$(SRC_DIR)/08_move.c \
			$(SRC_DIR)/07_events.c \
			$(SRC_DIR)/09_error.c \

#~~~~~~OBJETS~~~~~
OBJ_DIR = ./obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#~~~~~~INCLUDES~~~~~~
INC_DIR = ./includes
INCS = $(INC_DIR)/*.h

#~~~~~~MINILIBX~~~~~~
MLX_INC = -I minilibx-linux -I mlx_linux
MLX_FIR = ./minilibx-linux

#~~~~~~GNL~~~~~~
GNL_DIR = ./get_next_line/
GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

#~~~~~~LIBFT~~~~~
LIBFT_DIR = ./libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a

#~~~~~~COPILATIION INFO~~~~~~
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS:= -L $(LIBFT_DIR) -lft

#~~~~~~OS COMPILATION~~~~~~
# LINUX
#MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
# MAC
INC_LIB=/usr/local/lib
MLX_FLAGS = -L.. -lmlx -L$(INC_LIB) -lXext -lX11

#~~~~~~COMPILATION RULES~~~~~~
all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C ${LIBFT_DIR}
	@echo "\033[1;33m\nCOMPILING SO_LONG..."
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MLX_FLAGS) $(LFLAGS) -o $@
	@echo "\033[1;32m./so_long created\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MLX_INC) -O3 -c $< -o $@

clean:
	@make clean -C ${LIBFT_DIR}
	@echo "\033[1;31mDeleting so_long object..."
	@$(RM) $(OBJS) $(GNL_OBJS)
	@echo "\033[1;32mDone\n"

fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@echo "\033[1;31mDeleting so_long executable..."
	@$(RM) $(NAME)
	@echo "\033[1;32mDone\n"

re:    fclean all

bonus:    re

.PHONY: all clean fclean re bonus
