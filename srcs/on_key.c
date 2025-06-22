/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:13:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/22 21:35:18 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key(int keycode, t_fractol *fractol)
{
	printf("keycode = %d\n", keycode);
	fractol->point.pixel = fractol->point.zoom;
	if (keycode == ESC)
		exit(0);
	else if (keycode == RIGHT)
		fractol->point.draw_start.re += 0.1 * fractol->point.pixel;
	else if (keycode == LEFT)
		fractol->point.draw_start.re -= 0.1 * fractol->point.pixel;
	else if (keycode == UP)
		fractol->point.draw_start.im += 0.1 * fractol->point.pixel;
	else if (keycode == DOWN)
		fractol->point.draw_start.im -= 0.1 * fractol->point.pixel;
	else
		return (1);

	// どの矢印キーでも共通して再描画
	mandel_arr_init(fractol->fractal_values, &fractol->point);
	mandelbrot(&fractol->data, fractol->fractal_values);
	return (1);
}

