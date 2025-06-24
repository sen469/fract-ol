/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:26:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/24 13:35:01 by ssawa            ###   ########.fr       */
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
#include "struct.h"



# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define MANDELBROT 1
# define JULIA 2

// # define ESC 65307
// # define RIGHT 65363
// # define UP 65362
// # define DOWN 65364
// # define LEFT 65361

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ESC 53
# define RIGHT 124
# define UP 126
# define DOWN 125
# define LEFT 123


int		is_set(char **s, t_data *d, int ac, t_comp *param);
void	mlx_setup(t_data *d);

// mandelbrot
void	array_init(t_val arr[HEIGHT][WIDTH], t_point *point, int type);

// 集合の判定
void	judge(t_fractol *fractol);

// 入力系
int		on_key(int keycode, t_fractol *fractol);
int		on_scroll(int button, int x, int y, t_fractol *fractol);
void	zoom(int x, int y, t_fractol *fractol);

// mlx_utils
// 色を塗る
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// マンデルブロ集合のpointの初期
void	point_init(t_point *point);
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
void	mapping(t_data *data, t_val arr[HEIGHT][WIDTH], int endian);
// マンデルブロのmain部分
void	draw(t_data *data, t_val arr[HEIGHT][WIDTH], t_comp *param);
// ac == 4のときの処理
// void	julia_const_init(t_fractol *fractal, char *re, char *im);

#endif
