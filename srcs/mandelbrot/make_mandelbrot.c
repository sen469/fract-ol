/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:35:48 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/18 22:54:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

static t_comp	make_next(t_comp *pre, t_comp *pos)
{
	t_comp	tmp;

	tmp = comp_multiple(*pre, *pre);
	tmp.re += pos->re;
	tmp.im += pos->im;
	return (tmp);
}

static void	calculate(t_val *v)
{
	int	i;
	
	i = 0;
	v->is_div = 0;
	while (i++ < 50 && comp_abs(v->now) > 2)
	{
		v->now = make_next(&v->pre, &v->now);
		v->pre = v->now;
		v->cnt++;
	}
	if (comp_abs(v->now) > 2)
		v->is_div = 1;
}

void	make_mandelbrot(t_point *p, t_data *data)
{
	int		i, j;
	t_val	v;

	p->pixel = 3.0 / 200 / p->zoom;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			v.pos.re = p->sta.re + (i - HEIGHT / 2) * p->pixel;
			v.pos.im = p->sta.im + (j - WIDTH / 2) * p->pixel;
			v.pre.re = 0;
			v.pre.im = 0;
			v.now = v.pos;
			v.cnt = 0;
			v.is_div = 0;

			calculate(&v);

			// ピクセルに色を設定
			int color = (v.is_div == 0) ? 0x000000 : 0x00FF00 + v.cnt * 10;
			// ピクセル描画関数を使って描画
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
	// 最後にイメージをウィンドウに表示
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
