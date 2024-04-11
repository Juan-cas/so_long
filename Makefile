# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3 #-fsanitize=address,undefined,leak
LFLAGS := -lmlx -framework OpenGL -framework AppKit

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
$(SRC_DIR)/utils/mlx_utils.c \
$(SRC_DIR)/parsing/parsing.c \
$(SRC_DIR)/utils/imagetowindow.c \
$(SRC_DIR)/utils/map_populator.c \
$(SRC_DIR)/movements/movements.c

# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Libraries
LIBS := -L$(LIBFT_DIR) -lft 

# Executable
TARGET := solong
NAME := $(TARGET)

# Conditional compilation based on target
ifeq ($(MAKECMDGOALS),debug)
 CFLAGS += -g
else ifeq ($(MAKECMDGOALS),optimize)
 CFLAGS += -O2
endif

all: libft $(TARGET)

# Libft targets
libft:
	$(MAKE) -C $(LIBFT_DIR)

libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

clean: libft_clean 
	rm -rf $(OBJ_DIR)

fclean: clean libft_fclean 
	rm -f $(TARGET)

re: fclean all

bonus:: CFLAGS += -D BONUS=1
bonus: re

rebonus: fclean bonus

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LFLAGS)

# Object file rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets
.PHONY: all clean fclean re bonus rebonus

