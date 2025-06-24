/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/24 13:35:48 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	loop_update(void *param)
{
	t_fractol *fractol = (t_fractol *)param;

	if (fractol->need_redraw)
	{
		array_init(fractol->fractal_values, &fractol->point, fractol->data.fractal_type);
		fractol->need_redraw = 0;
	}
	printf("judge, param = %.4e, %.4e\n", fractol->param.re, fractol->param.im);
	draw(&fractol->data, fractol->fractal_values, &fractol->param);
	return (0);
}

int	main(int ac, char **av)
{
	// int	flag;
	t_fractol	fractol;

	if (ac <= 1)
		return (0);
	/*
	flag = (ac == 4 && !ft_strcmp(av[1], "julia"));
	if (flag)
	{
		printf("flag\n");
		julia_const_init(&fractol, av[2], av[3]);
	}
	*/
	// else if (!is_set(av[1], &fractol.data, ac))
	if (!is_set(av, &fractol.data, ac, &fractol.param))
	{
		write(1, "mandelbrot julia\n", 17);
		return (0);
	}

	// 共通初期化
	mlx_setup(&fractol.data);
	point_init(&fractol.point);
	judge(&fractol);
	fractol.need_redraw = 0;
	mlx_key_hook(fractol.data.win_ptr, on_key, &fractol);
	mlx_mouse_hook(fractol.data.win_ptr, on_scroll, &fractol);
	mlx_loop_hook(fractol.data.mlx_ptr, loop_update, &fractol);
	mlx_loop(fractol.data.mlx_ptr);
	/*
	if (flag)
	{
		printf("flag\n");
		mlx_setup(&fractol.data);
		point_init(&fractol.point);
		julia_const_init(&fractol, av[2], av[3]);
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
	else if (is_set(av[1], &fractol.data))
	{
		mlx_setup(&fractol.data);
		point_init(&fractol.point);
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
	else
	{
		write(1, "mandelbrot julia\n", 17);
	}
	*/
	return (0);
}
