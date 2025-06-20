/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:36:24 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"


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
			while (c++ < 100)
			{
				arr[i][j].now = comp_add(arr[i][j].pos, \
						comp_multiple(arr[i][j].pre, arr[i][j].pre));
				arr[i][j].pre = arr[i][j].now;
				arr[i][j].cnt++;
				if (comp_abs(arr[i][j].now) > 2)
				{
					arr[i][j].is_div = 1;
					break;
				}
			}
			j++;
		}
		i++;
	}
}

void	mandelbrot(t_data *data, t_val arr[HEIGHT][WIDTH])
{
	calculate(arr);
	int i = 400;
	int j = 400;
	printf("%.2e, %.2e\n", arr[i][j].now.re, arr[i][j].now.im);
	mandel_mapping(data, arr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
