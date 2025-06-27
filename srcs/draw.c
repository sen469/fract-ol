/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:33:24 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "struct.h"

static void	my_cal(t_val arr[HEIGHT][WIDTH], \
						int fractal_type, t_comp *param);

void	draw(t_data *data, t_val arr[HEIGHT][WIDTH], t_comp *param)
{
	my_cal(arr, data->fractal_type, param);
	mapping(data, arr, data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

static int	abs_judge(t_val *pos)
{
	if (comp_abs(pos->now) > 2)
	{
		pos->diverged = 1;
		return (1);
	}
	return (0);
}

static void	process(t_val *pos, int type, t_comp *param)
{
	if (type == MANDELBROT)
	{
		pos->now = comp_add(pos->pos, \
				comp_multiple(pos->pre, pos->pre));
		pos->pre = pos->now;
		pos->cnt++;
	}
	else if (type == JULIA)
	{
		pos->now = comp_add(*param, \
				comp_multiple(pos->pre, pos->pre));
		pos->pre = pos->now;
		pos->cnt++;
	}
	else if (type == BURNING_SHIP)
	{
		pos->now = comp_add(pos->pos, \
				comp_multiple_burning_ship(pos->pre));
		pos->pre = pos->now;
		pos->cnt++;
	}
}

static void	my_cal(t_val arr[HEIGHT][WIDTH], int fractal_type, t_comp *param)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			cnt = 0;
			while (cnt++ < MAX_ITER)
			{
				if (arr[i][j].diverged == 0)
					process(&arr[i][j], fractal_type, param);
				if (arr[i][j].diverged || abs_judge(&arr[i][j]))
					break ;
			}
			j++;
		}
		i++;
	}
}
