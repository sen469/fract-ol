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

void	make_mandelbrot()
{

}

/*
// array init に同じ内容を記入
void	arr_init(t_val *a, t_point *p, int i, int j)
{
	// 1ピクセル当たりの大きさを記録
	p->pixel = 3.0 / 200 / p->zoom;
	i = HEIGHT - i;
	a->pos.re = p->sta.re + i * p->pixel;
	a->pos.im = p->sta.im + j * p->pixel;
}
*/


/*
void	make_mandelbrot(t_point *p, void *img)
{
	t_val	arr[WIDTH][HEIGHT];
	int		i;
	int		j;
	int		flag;

	flag = 1;
	while (flag)
	{
		i = 0;
		j = 0;
		while (i < HEIGHT)
		{
			while (j < WIDTH)
			{
				arr_init(&arr[i][j], p, i, j);
				calculate(&arr[i][j]);
				if (arr[i][j].is_div == 0)
				{
					// img 黒塗り
				}
				else
				{
					// 現在の回数で色を塗る
				}
				j++;
			}
			i++;
		}
		// show image;
		// 
	}
}
*/
