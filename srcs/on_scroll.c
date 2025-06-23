/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_scroll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:51:45 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/23 19:04:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_scroll(int button, int x, int y, t_fractol *fractol)
{
	fractol->need_redraw = 0;
	// printf("x = %d, y = %d\n", x, y);
	if (button == SCROLL_UP)
	{
		fractol->point.zoom *= 1.1;
	}
	else if (button == SCROLL_DOWN)
	{
		fractol->point.zoom *= 0.9;
	}
	else
	{
		return (0);
	}
	/*
	else
	{
		fractol->need_redraw = 1;
		return (0);
	}
	*/
	fractol->need_redraw = 1;
	zoom(x, y, fractol);
	// mandel_arr_init(fractol->fractal_values, &fractol->point);
	// mandelbrot(&fractol->data, fractol->fractal_values);
	return (1);
}
