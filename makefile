# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 19:56:51 by ddania-c          #+#    #+#              #
#    Updated: 2023/05/15 16:27:44 by ddania-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~NAME~~~~~
NAME = so_long

#~~~~~~SOURCES~~~~~~
SRC_DIR = ./src
SRCS	= 	$(SRC_DIR)/main.c				\
			$(SRC_DIR)/get_next_line.c		\
			$(SRC_DIR)/get_next_line_utils.c\
			$(SRC_DIR)/00_check_ext.c		\
			$(SRC_DIR)/01_read_map.c		\
			$(SRC_DIR)/02_data_init.c		\
			$(SRC_DIR)/03_map_check.c		\
			$(SRC_DIR)/04_win_init.c		\
			$(SRC_DIR)/05_img_init.c		\
			$(SRC_DIR)/06_render.c			\
			$(SRC_DIR)/08_move.c			\
			$(SRC_DIR)/07_events.c			\
			$(SRC_DIR)/09_exit_clean.c		\

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
MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
# MAC
#INC_LIB=/usr/local/lib
#MLX_FLAGS = -L.. -lmlx -L$(INC_LIB) -lXext -lX11

#~~~~~~COMPILATION RULES~~~~~~
all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C ${LIBFT_DIR}
	@echo "Compiling So_long..."
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MLX_FLAGS) $(LFLAGS) -o $@
	@echo "OK\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MLX_INC) -O3 -c $< -o $@

clean:
	@make clean -C ${LIBFT_DIR}
	@echo "Deleting so_long object..."
	@$(RM) $(OBJS) $(GNL_OBJS)
	@echo "OK\n"

fclean: clean
	@make fclean -C ${LIBFT_DIR}
	@echo "Deleting so_long executable..."
	@$(RM) $(NAME)
	@echo "OK\n"

re:		fclean all

bonus:	re

.PHONY:	all clean fclean re bonus
