/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:11:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/24 13:37:27 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 800
# define HEIGHT 800

typedef struct s_comp
{
	double	re;
	double	im;
}				t_comp;

// マウスの相対座標、絶対座標、ピクセルの大きさ、倍率、画像スタートの絶対座標
typedef struct s_point
{
	// 倍率
	double	zoom;
	// ピクセル当たりの大きさ、変化量みたいなもの
	double	pixel;
	// startの絶対座標
	t_comp	sta;
	// 描画範囲のスタート範囲 行列として考える
	t_comp	draw_start;
}	t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	void	*img_ptr;
	int		bpp;
	int		line_len;
	int		endian;
	int		fractal_type;
}	t_data;

typedef struct s_val
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
	int		diverged;
}	t_val;

typedef struct s_fractol
{
	// mlx周りのものを扱う
	t_data	data;
	// カーソルや、描画のスタート地点座標周りの値を扱う
	t_point	point;
	// 各ピクセルの座標平面上の座標w
	t_val	fractal_values[HEIGHT][WIDTH];
	// 再描画が必要かどうか
	int		need_redraw;
	t_comp	param;
}	t_fractol;

#endif
