/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/24 13:49:35 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include "struct.h"

static void	calculate_mandelbrot(t_val arr[HEIGHT][WIDTH]);
static void	calculate_julia(t_val arr[HEIGHT][WIDTH], t_comp *param);
static void	calculate_burning_ship(t_val arr[HEIGHT][WIDTH]);

void	draw(t_data *data, t_val arr[HEIGHT][WIDTH], t_comp *param)
{
	if (data->fractal_type == MANDELBROT)
		calculate_mandelbrot(arr);
	else if (data->fractal_type == JULIA)
		calculate_julia(arr, param);
	else if (data->fractal_type == BURNING_SHIP)
		calculate_burning_ship(arr);
	mapping(data, arr, data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

static void	calculate_mandelbrot(t_val arr[HEIGHT][WIDTH])
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

static void	calculate_julia(t_val arr[HEIGHT][WIDTH], t_comp *param)
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
			while (cnt++ < 50)
			{
				if (arr[i][j].diverged == 0)
				{
					arr[i][j].now = comp_add(*param, \
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

static void	calculate_burning_ship(t_val arr[HEIGHT][WIDTH])
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
							comp_multiple_burning_ship(arr[i][j].pre));
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
