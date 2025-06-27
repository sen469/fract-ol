/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:56:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac <= 1)
		return (0);
	// 初期化関数を作る
	fractol.need_redraw = 0;
	fractol.move = 0;
	fractol.param.re = 0;
	fractol.param.im = 0;
	fractol.fractal_values = malloc_array();
	if (!is_set(av, &fractol.data, ac, &fractol.param))
	{
		write(1, "mandelbrot julia\n", 17);
		return (0);
	}
	mlx_setup(&fractol.data);
	point_init(&fractol.point);
	judge(&fractol);
	mlx_key_hook(fractol.data.win_ptr, on_key, &fractol);
	mlx_mouse_hook(fractol.data.win_ptr, on_scroll, &fractol);
	mlx_loop_hook(fractol.data.mlx_ptr, loop_update, &fractol);
	mlx_hook(fractol.data.win_ptr, 17, 0, on_close, &fractol);
	mlx_hook(fractol.data.win_ptr, 6, 1L << 6, on_mouse_move, &fractol);
	mlx_loop(fractol.data.mlx_ptr);
	free_array(fractol.fractal_values);
	return (0);
}
