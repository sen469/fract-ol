# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 21:22:23 by ssawa             #+#    #+#              #
#    Updated: 2025/08/25 15:00:00 by ssawa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################
#            Library Settings          #
########################################

NAME        = fractol

LIBFT       = ./incs/libft/libft.a
LIBFT_DIR   = ./incs/libft

MLX         = ./incs/mlx/libmlx.a
MLX_DIR     = ./incs/mlx

########################################
#        Compiler Configuration        #
########################################

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O2

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_FLAGS   = -lXext -lX11 -lm -lbsd
endif

ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -framework OpenGL -framework AppKit
endif

INCLUDES    = -I./incs -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

SRCS = \
	srcs/judge.c \
	srcs/main.c \
	srcs/array_init.c \
	srcs/draw.c \
	srcs/mapping.c \
	srcs/comp_abs.c \
	srcs/comp_add.c \
	srcs/comp_multiple.c \
	srcs/ft_atof.c \
	srcs/is_set.c \
	srcs/mlx_setup.c \
	srcs/get_psychedelic_color.c \
	srcs/my_mlx_pixel_put.c \
	srcs/on_key.c \
	srcs/on_scroll.c \
	srcs/zoom.c \
	srcs/point_init.c \
	srcs/on_close.c \
	srcs/on_mouse_move.c \
	srcs/skip.c \
	srcs/loop_update.c \
	srcs/free_array.c \
	srcs/malloc_array.c

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(B_OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

# bonusターゲットも一応定義（同じ内容）
bonus: $(NAME)

# Libftビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# mlxビルド（存在しない場合は自動でgit clone）
$(MLX):
ifeq ($(UNAME_S),Linux)
	if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Minilibxが見つかりません。Cloning Linux版..."; \
		git clone git@github.com:42paris/minilibx-linux.git $(MLX_DIR); \
	fi
endif
ifeq ($(UNAME_S),Darwin)
	if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Minilibxが見つかりません。Cloning mac版..."; \
		git clone git@github.com:dannywillems/minilibx-mac-osx.git $(MLX_DIR); \
	fi
endif
	$(MAKE) -C $(MLX_DIR)

# オブジェクトファイル作成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# オブジェクト削除
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS) $(B_OBJS)

# バイナリ・ライブラリ削除
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 全クリーン&再ビルド
re: fclean all

BONUS_SRCS =
B_OBJS = $(BONUS_SRCS:.c=.o)

# --- optional run target ---
run: re
	./$(NAME) mandelbrot

rm_mlx:
	rm -rf $(MLX_DIR)
.PHONY: all bonus clean fclean re

