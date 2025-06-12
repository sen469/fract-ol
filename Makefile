########################################
#            Library Settings          #
########################################

NAME        = fractol

LIBFT       = ./incs/libft/libft.a
LIBFT_DIR   = ./incs/libft

########################################
#        Compiler Configuration        #
########################################

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I./includes -I$(LIBFT_DIR)

########################################
#       Source & Object Files          #
########################################

SRC = \

BONUS_SRC = \

OBJ     = $(SRC:.c=.o)
B_OBJ   = $(BONUS_SRC:.c=.o)

########################################
#               Rules                  #
########################################

# デフォルトターゲット
all: $(NAME)

# ライブラリ作成: 通常 + bonusもまとめてアーカイブ
$(NAME): $(LIBFT) $(OBJ) $(B_OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) $(B_OBJ)

# bonusターゲットも一応定義（同じ内容）
bonus: $(NAME)

# Libftビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# オブジェクトファイル作成
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# オブジェクト削除
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(B_OBJ)

# バイナリ・ライブラリ削除
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 全クリーン&再ビルド
re: fclean all

.PHONY: all bonus clean fclean re
