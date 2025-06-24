/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:56:56 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/23 19:03:41 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_fractol *fractol)
{
	t_comp	mouse_pos_absolute;
	double	pixel_size;

	x--;
	y--;
	fractol->point.pixel = 3.0 / WIDTH / fractol->point.zoom;
	pixel_size = fractol->point.pixel;
	mouse_pos_absolute = fractol->fractal_values[y][x].pos;
	fractol->point.draw_start.re = mouse_pos_absolute.re - x * pixel_size;
	fractol->point.draw_start.im = mouse_pos_absolute.im - y * pixel_size;
}
