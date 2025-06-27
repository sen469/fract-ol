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
#include "libft.h"
#include "struct.h"

int	init_fractor(t_fractol *fractol)
{
	fractol->need_redraw = 0;
	fractol->move = 0;
	fractol->param.re = 0;
	fractol->param.im = 0;
	fractol->fractal_values = malloc_array();
	if (fractol == NULL)
		return (0);
	else
		return (1);
}

void	err_message(void)
{
	ft_putstr_fd("\n\033[31;1mWRONG INPUT FORMAT\n\n", 1);
	ft_putstr_fd("\033[33mInput Format: ./fractol", 1);
	ft_putstr_fd("<fractol_type> <parameters>\n\n", 1);
	ft_putstr_fd("\tfractol_type           : Julia, Mandelbrot or ", 1);
	ft_putstr_fd("Burning_ship\n", 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac <= 1)
		err_message();
	if (!init_fractor(&fractol))
	{
		perror("MEMORY ALLOCATE FAILED\n");
		return (1);
	}
	if (!is_set(av, &fractol.data, ac, &fractol.param))
		err_message();
	mlx_setup(&fractol.data);
	point_init(&fractol.point);
	judge(&fractol);
	mlx_key_hook(fractol.data.win_ptr, on_key, &fractol);
	mlx_mouse_hook(fractol.data.win_ptr, on_scroll, &fractol);
	mlx_loop_hook(fractol.data.mlx_ptr, loop_update, &fractol);
	mlx_hook(fractol.data.win_ptr, 17, 0, on_close, &fractol);
	mlx_hook(fractol.data.win_ptr, 6, 1L << 6, on_mouse_move, &fractol);
	mlx_loop(fractol.data.mlx_ptr);
	free_array(&fractol);
	return (0);
}
