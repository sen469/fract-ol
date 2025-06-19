/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:26:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/19 15:41:03 by ssawa            ###   ########.fr       */
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
# define HEIGHT 600

typedef struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
}	t_mlx;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_data;

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
	t_comp	m_absoluate;
	// マウスの相対座標
	t_comp	m_relative;
}				t_point;

typedef struct	s_val
{
	t_comp	pos;
	t_comp	pre;
	t_comp	now;
	double	abs;
	int		cnt;
	int		is_div;
}				t_val;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}				t_color;

typedef struct s_all {
	t_data	data;
	t_point	point;
} t_all;

// main process
void	input_init(t_comp *input, char *re, char *im);

// mandelbrot
void	init_array(t_val ***arr, t_point *p);
// mandelbrotを作る
void	make_mandelbrot(t_point *p, t_data *data);



// mlx_utils
void	change_color(t_color *col);
// 色を塗る
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// 未完成
int	is_keycode(int keycode);
// utils
// 複素数の掛け算
t_comp	comp_multiple(t_comp a, t_comp b);
// 複素数の絶対値
double	comp_abs(t_comp val);
// 文字列を小数に変換
double	ft_atof(const char *str);

// 座標初期化系
void	point_init(t_point *point);

// mandelbrot
void	mandelbrot(void);




#endif
