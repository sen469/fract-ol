/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/22 21:33:59 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"

static void	calculate(t_val arr[HEIGHT][WIDTH]);

void	mandelbrot(t_data *data, t_val arr[HEIGHT][WIDTH])
{
	calculate(arr);
	mandel_mapping(data, arr, data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	write(1, "map update\n", 11);
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 600, 700, WHITE, );
}

static void	calculate(t_val arr[HEIGHT][WIDTH])
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			c = 0;
			while (c++ < 50)
			{
				if (arr[i][j].diverged == 0)
				{
					arr[i][j].now = comp_add(arr[i][j].pos, \
							comp_multiple(arr[i][j].pre, arr[i][j].pre));
					arr[i][j].pre = arr[i][j].now;
					arr[i][j].cnt++;
				}
				if (comp_abs(arr[i][j].now) > 2)
				{
					arr[i][j].diverged = 1;
					break;
				}
			}
			j++;
		}
		i++;
	}
}

