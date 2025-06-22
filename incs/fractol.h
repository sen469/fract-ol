/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:26:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/22 16:40:17 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
#include <math.h>

# define WIDTH 800
# define HEIGHT 800

// # define WAVE_LENGTH_R 0.1
// # define WAVE_LENGTH_G 0.1
// # define WAVE_LENGTH_B 0.2

// # define RATIO_R 0.2
// # define RATIO_G 0.4
// # define RATIO_B 0.5
// # define RANGE 1
// # define RGB 255

// # define LIMIT 6.0

# define BLACK 0x000000
# define WHITE 0xFFFFFF

typedef struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

// マウスの相対座標、絶対座標、ピクセルの大きさ、倍率、画像スタートの絶対座標
typedef struct	s_point
{
	// 倍率
	double	zoom;
	// ピクセル当たりの大きさ、変化量みたいなもの
	double	pixel;
	// startの絶対座標
	t_comp	sta;
	// マウスの絶対座標
	t_comp	mouse_abs;
	// マウスの相対座標
	t_comp	mouse_rel;
	// 描画範囲のスタート範囲 行列として考える
	t_comp	str_abs;
	// 描画範囲の終了 行列のとして考える
	t_comp	end_abs;
}				t_point;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	void	*img_ptr;
	int		bpp;
	int		line_len;
	int		endian;
	int		set;
	// 座標類
	t_point	point;
}				t_data;


typedef struct	s_val
{
	// 絶対座標
	t_comp	pos;
	// z_n
	t_comp	pre;
	// z_(n + 1)
	t_comp	now;
	// |z|
	double	abs;
	// 現在の回数
	int		cnt;
	// 発散かどうかの判定
	int		is_div;
}				t_val;

/*
typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}				t_color;
*/


int	is_set(char *s, t_data *d);
void	mlx_setup(t_data *d);

// mandelbrot
void	mandel_arr_init(t_val **arr, t_point *point);

void	judge(t_data *data, t_val **arr);


# define MANDELBROT 1
# define JULIA 2

# define ESC 65307
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define LEFT 65361























// フリーと正常終了
void	exit_free(t_val **arr);
// 配列のフリー
void	free_arr(t_val **arr);

int	on_key(int keycode, t_data *data);

// mandelbrotを作る
// void	make_mandelbrot(t_point *p, t_data *data);
// mlx_utils
// void	change_color(t_color *col);
// 色を塗る
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// マンデルブロ集合のpointの初期
void	mandel_point_init(t_point *point);
// 未完成
int	is_keycode(int keycode);
// utils
// 複素数の掛け算
t_comp	comp_multiple(t_comp a, t_comp b);
// 複素数の足し算
t_comp	comp_add(t_comp a, t_comp b);
// 複素数の絶対値
double	comp_abs(t_comp val);
// 文字列を小数に変換
double	ft_atof(const char *str);
// サイケデリックな画像を生成
unsigned int get_psychedelic_color(t_val *v, int endian);
// マンデルブロのマッピング
void	mandel_mapping(t_data *data, t_val **arr, int endian);
// マンデルブロのmain部分
void	mandelbrot(t_data *data, t_val **arr);
// arrayのまろっく
t_val	**malloc_arr(void);





#endif
