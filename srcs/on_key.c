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
#include "struct.h"

int	on_key(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->point.pixel = 3.0 / WIDTH / fractol->point.zoom;
	if (keycode == ESC)
	{
		free_array(fractol);
		exit(0);
	}
	else if (keycode == RIGHT)
		fractol->point.draw_start.re += 10 * fractol->point.pixel;
	else if (keycode == LEFT)
		fractol->point.draw_start.re -= 10 * fractol->point.pixel;
	else if (keycode == UP)
		fractol->point.draw_start.im += 10 * fractol->point.pixel;
	else if (keycode == DOWN)
		fractol->point.draw_start.im -= 10 * fractol->point.pixel;
	else
		return (1);
	fractol->need_redraw = 1;
	return (1);
}
