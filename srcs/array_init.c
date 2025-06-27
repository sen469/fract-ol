/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:28:57 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:54:52 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	array_init(t_val **arr, t_point *point, int type)
{
	int	i;
	int	j;

	point->pixel = (3.0 / WIDTH) / point->zoom;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			arr[i][j].cnt = 0;
			arr[i][j].diverged = 0;
			arr[i][j].pos.re = point->draw_start.re + point->pixel * j;
			arr[i][j].pos.im = point->draw_start.im + point->pixel * i;
			if (type == MANDELBROT || type == BURNING_SHIP)
			{
				arr[i][j].pre.re = 0;
				arr[i][j].pre.im = 0;
			}
			else if (type == JULIA)
				arr[i][j].pre = arr[i][j].pos;
			j++;
		}
		i++;
	}
}
