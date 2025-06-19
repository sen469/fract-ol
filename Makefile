########################################
#            Library Settings          #
########################################

NAME        = fractol

LIBFT       = ./incs/libft/libft.a
LIBFT_DIR   = ./incs/libft

MLX         = ./incs/mlx/libmlx.a
MLX_DIR      = ./incs/mlx/

########################################
#        Compiler Configuration        #
########################################

CC          = cc
# CFLAGS      = -Wall -Wextra -Werror
CFLAGS      = -Wall -Wextra
MLX_FLAGS = -lXext -lX11 -lm -lbsd
INCLUDES    = -I./includes -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

SRC = \
	  srcs/input_init.c \
	  srcs/main.c \
	  srcs/utils/comp_multiple.c \
	  srcs/utils/ft_atof.c \
	  srcs/mandelbrot/mandelbrot.c \
	  srcs/mandelbrot/make_mandelbrot.c \
	  srcs/mandelbrot/init_array.c \
	  srcs/utils/mlx_utils/change_color.c \
	  srcs/utils/mlx_utils/is_keycode.c \
	  srcs/utils/mlx_utils/point_init.c \
	  srcs/utils/comp_abs.c \
	  srcs/utils/mlx_utils/my_mlx_pixel_put.c \





BONUS_SRC = \

OBJ     = $(SRC:.c=.o)
B_OBJ   = $(BONUS_SRC:.c=.o)

########################################
#               Rules                  #
########################################

# デフォルトターゲット
all: $(NAME)

# ライブラリ作成: 通常 + bonusもまとめてアーカイブ
$(NAME): $(LIBFT) $(MLX) $(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(B_OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

# bonusターゲットも一応定義（同じ内容）
bonus: $(NAME)

# Libftビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# mlxビルド
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# オブジェクトファイル作成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# オブジェクト削除
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	# $(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ) $(B_OBJ)

# バイナリ・ライブラリ削除
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	# $(MAKE) -C $(MLX_DIR) fclean
	rm -f $(NAME)

# 全クリーン&再ビルド
re: fclean all

.PHONY: all bonus clean fclean re
