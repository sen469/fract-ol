# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 21:22:23 by ssawa             #+#    #+#              #
#    Updated: 2025/06/22 15:21:52 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
# INCLUDES    = -I./includes -I$(LIBFT_DIR)
INCLUDES    = -I./incs -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

SRCS = \
	srcs/judge.c \
	srcs/main.c \
	srcs/mandel_arr_init.c \
	srcs/mandelbrot.c \
	srcs/mandel_mapping.c \
	srcs/comp_abs.c \
	srcs/comp_add.c \
	srcs/comp_multiple.c \
	srcs/ft_atof.c \
	srcs/is_set.c \
	srcs/mlx_setup.c \
	srcs/get_psychedelic_color.c \
	srcs/my_mlx_pixel_put.c \
	srcs/point_init.c \
	srcs/on_key.c \
	srcs/malloc_arr.c \
	srcs/exit_free.c \
	srcs/free_arr.c \
	srcs/mandel_point_init.c
	# srcs/utils/mlx_utils/change_color.c 




BONUS_SRCS = \

OBJS     = $(SRCS:.c=.o)
B_OBJS   = $(BONUS_SRCS:.c=.o)

########################################
#               Rules                  #
########################################

# デフォルトターゲット
all: $(NAME)

# ライブラリ作成: 通常 + bonusもまとめてアーカイブ
$(NAME): $(LIBFT) $(MLX) $(OBJS) $(B_OBJS)
	ulimit -s 65532
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(B_OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

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
	rm -f $(OBJS) $(B_OBJS)

# バイナリ・ライブラリ削除
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	# $(MAKE) -C $(MLX_DIR) fclean
	rm -f $(NAME)

# 全クリーン&再ビルド
re: fclean all

BONUS_SRCS =
B_OBJS = $(BONUS_SRCS:.c=.o)

# --- optional run target ---
run: re
	./$(NAME) mandelbrot

.PHONY: all bonus clean fclean re
