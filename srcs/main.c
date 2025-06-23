/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/22 22:04:03 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_update(void *param)
{
	t_fractol *fractol = (t_fractol *)param;

	if (fractol->need_redraw)
	{
		mandel_arr_init(fractol->fractal_values, &fractol->point);
		fractol->need_redraw = 0;
	}
	mandelbrot(&fractol->data, fractol->fractal_values);
	printf("zoom = %.8e\n", fractol->point.zoom);
		// fractol->need_redraw = 0;

		/*
	if (fractol->need_redraw)
	{
	}
	*/
	return (0);
}

int	main(int ac, char **av)
{
	int	flag;
	t_fractol	fractol;

	if (ac <= 1)
		return (0);
	flag = (ac == 4 && ft_strcmp(av[1], "julia"));
	if (flag)
	{
		return (0);
	}
	else if (is_set(av[1], &fractol.data))
	{
		mlx_setup(&fractol.data);
		mandel_point_init(&fractol.point);
		judge(&fractol);
		fractol.need_redraw = 0;
		// キー入力を受け取ったときにはmapを初期化する
		mlx_key_hook(fractol.data.win_ptr, on_key, &fractol);
		// マウスイベントの登録（正しい使い方）
		mlx_mouse_hook(fractol.data.win_ptr, on_scroll, &fractol);
		// キー入力を受け取らない場合はマップを更新していく
		mlx_loop_hook(fractol.data.mlx_ptr, loop_update, &fractol);
		mlx_loop(fractol.data.mlx_ptr);
	}
	return (0);
}
