NAME = so_long

# directorio de la biblioteca mlx
MLX_INC = -I minilibx-linux -I mlx_linux
MLX_FIR = ./minilibx-linux

# directorios de archivos fuente y bojets
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./includes

# Archivos fuente y objertos
SRCS = $(SRC_DIR)/main.c\
			$(SRC_DIR)/window.c\
			$(SRC_DIR)/event.c\
			$(SRC_DIR)/destroy_data.c\
			$(SRC_DIR)/render.c\
			$(SRC_DIR)/data.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INCS = $(INC_DIR)/*.h

# opciones de compilacion
CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#### para ;inux activar este comando
MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

### para mac activar este comando
#INC_LIB=/usr/local/lib
#MLX_FLAGS = -L.. -lmlx -L$(INC_LIB) -lXext -lX11 -lm

# reglas
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33m\nCOMPILING SO_LONG..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@
	@echo "\033[1;32m./so_long created\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(MLX_INC) -O3 -c $< -o $@

clean:
	@echo "\033[0;31mDeleting so_long object..."
	@$(RM) $(OBJS)
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting so_long executable..."
	@$(RM) $(NAME)
	@echo "\033[1;32mDone\n"

re:    fclean all

bonus:    re

.PHONY: all clean fclean re bonus
