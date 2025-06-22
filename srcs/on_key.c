/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:13:24 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/22 16:40:38 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key(int keycode, t_data *data)
{
	printf("keycode = %d\n", keycode);
	data->point.pixel = data->point.zoom;
	if (keycode == ESC)
	{
		exit(0);
	}
	else if (keycode == RIGHT)
	{
		printf("RIGHT\n");
		data->point.mouse_abs.re += 10 * data->point.pixel;
		printf("RIGHT FINISH\n");
	}
	else if (keycode == LEFT)
	{
		data->point.mouse_abs.re -= 10 * data->point.pixel;
	}
	else if (keycode == UP)
	{
		data->point.mouse_abs.im += 10 * data->point.pixel;
	}
	else if (keycode == DOWN)
	{
		data->point.mouse_abs.im -= 10 * data->point.pixel;
	}
	else
	{ }
	return (1);
}
