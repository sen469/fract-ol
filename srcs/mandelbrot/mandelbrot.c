/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/16 22:17:42 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

int	on_close(void *param)
{
	(void)param;
	exit(0);
}

int	on_key(int keycode, void *param)
{
	(void)param;
	// Escキー
	// printf("%d\n", keycode);
	if (keycode == 65307)
	{
		write(1, "YOU PRESS ESC.\n", 15);
		exit(0);
	}
	return (0);
}

void	mandelbrot(void)
{
	t_mlx	mlx;
	t_data	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mandelbrot Window");

	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// 描画
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 17, 0, on_close, NULL);
	mlx_key_hook(mlx.win, on_key, NULL);
	mlx_loop(mlx.mlx);
}
