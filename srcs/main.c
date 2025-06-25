/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/25 13:08:14 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	loop_update(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;

	if (fractol->need_redraw)
	{
		array_init(fractol->fractal_values, &fractol->point,\
				fractol->data.fractal_type);
		// printf("%.8e\n", fractol->point.zoom);
		fractol->need_redraw = 0;
	}
	draw(&fractol->data, fractol->fractal_values, &fractol->param);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac <= 1)
		return (0);
	if (!is_set(av, &fractol.data, ac, &fractol.param))
	{
		write(1, "mandelbrot julia\n", 17);
		return (0);
	}
	mlx_setup(&fractol.data);
	point_init(&fractol.point);
	judge(&fractol);
	fractol.need_redraw = 0;
	fractol.move = 0;
	fractol.param.re = 0;
	fractol.param.im = 0;
	mlx_key_hook(fractol.data.win_ptr, on_key, &fractol);
	mlx_mouse_hook(fractol.data.win_ptr, on_scroll, &fractol);
	mlx_loop_hook(fractol.data.mlx_ptr, loop_update, &fractol);
	mlx_hook(fractol.data.win_ptr, 17, 0, on_close, NULL);
	mlx_hook(fractol.data.win_ptr, 6, 1L<<6, on_mouse_move, &fractol);
	mlx_loop(fractol.data.mlx_ptr);
	return (0);
}
