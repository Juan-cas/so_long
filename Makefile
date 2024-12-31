# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address,leak
LFLAGS := -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -L/usr/lib/x11 -lXext -lX11

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
MLX_DIR := $(LIB_DIR)/mlx_linux

# Source files
SRC_FILES := $(SRC_DIR)/main.c \
$(SRC_DIR)/error/ft_error.c \
$(SRC_DIR)/parsing/get_next_line.c \
$(SRC_DIR)/parsing/map_maker.c \
$(SRC_DIR)/parsing/solong.c \
$(SRC_DIR)/utils/matrix_clear.c \
$(SRC_DIR)/parsing/map_check.c \
$(SRC_DIR)/parsing/correct_map_template.c \
$(SRC_DIR)/parsing/line1.c \
$(SRC_DIR)/utils/append.c \
$(SRC_DIR)/utils/find_n.c \
$(SRC_DIR)/utils/flood_fill.c \
$(SRC_DIR)/utils/coords_x_y_.c \
$(SRC_DIR)/utils/final_check.c \
$(SRC_DIR)/utils/init_structs.c \
$(SRC_DIR)/utils/find_coords.c \
$(SRC_DIR)/utils/free_data.c \
$(SRC_DIR)/utils/colors.c \
$(SRC_DIR)/parsing/parsing.c \
$(SRC_DIR)/utils/map_populator.c \
$(SRC_DIR)/movements/movements.c \
$(SRC_DIR)/error/ft_exit.c \
$(SRC_DIR)/utils/step_printer.c \
$(SRC_DIR)/movements/check_exit.c \
$(SRC_DIR)/movements/move_up.c \
$(SRC_DIR)/movements/move_down.c \
$(SRC_DIR)/movements/move_left.c \
$(SRC_DIR)/movements/move_right.c

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx

# Executable
TARGET := so_long
NAME := $(TARGET)

# Conditional compilation based on target
ifeq ($(MAKECMDGOALS),debug)
 CFLAGS += -g
else ifeq ($(MAKECMDGOALS),optimize)
 CFLAGS += -O2
endif

all: $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a $(TARGET)

# Build mlx_linux
$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

# Build libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean: libft_clean mlx_clean
	rm -rf $(OBJ_DIR)

fclean: libft_fclean mlx_fclean clean
	rm -f $(TARGET)

re: fclean all

bonus:: CFLAGS += -D BONUS=1
bonus: re

rebonus: fclean bonus

# Libft targets
libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

# mlx_linux targets
mlx_clean:
	$(MAKE) -C $(MLX_DIR) clean

mlx_fclean:
	$(MAKE) -C $(MLX_DIR) fclean

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LFLAGS)

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re bonus rebonus libft_clean libft_fclean mlx_clean mlx_fclean
