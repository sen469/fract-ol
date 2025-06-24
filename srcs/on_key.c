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
	fractol->point.pixel = 3.0 / WIDTH / fractol->point.zoom;
	if (keycode == ESC)
	{
		write(1, "ESC\n", 4);
		exit(0);
	}
	else if (keycode == RIGHT)
	{
		fractol->point.draw_start.re += 10 * fractol->point.pixel;
		// write(1, "RIGHT\n", 6);
	}
	else if (keycode == LEFT)
	{
		fractol->point.draw_start.re -= 10 * fractol->point.pixel;
		// write(1, "LEFT\n", 5);
	}
	else if (keycode == UP)
	{
		fractol->point.draw_start.im += 10 * fractol->point.pixel;
		// write(1, "UP\n", 3);
	}
	else if (keycode == DOWN)
	{
		fractol->point.draw_start.im -= 10 * fractol->point.pixel;
		// write(1, "DOWN\n", 5);
	}
	else
		return (1);

	fractol->need_redraw = 1;
	return (1);
}
