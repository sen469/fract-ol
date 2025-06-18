/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/18 23:01:56 by ssawa            ###   ########.fr       */
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
	t_val	arr[WIDTH][HEIGHT];

	(void)param;
	// ここで構造体の配列を宣言する
	// printf("%d\n", keycode);
	if (keycode == 65307)
	{
		// ESCキーの場合は正常終了
		write(1, "YOU PRESS ESC.\n", 15);
		exit(0);
	}
	else if (is_keycode(keycode))
	{
		// 任意のキー入力を受け取る
		// カーソルの回転、矢印キーの入力の2種類
		// 構造体の配列の初期化
		// 例えば、各値の初期値、座標
	}
	else
	{
		make_mandelbrot();
		// なんの入力も受け取らない
		// ここで計算する
	}
	// imageをウィンドウに表示する
	return (0);
}

void	mandelbrot(void)
{
	t_mlx	mlx;
	t_data	img;
	t_point	p;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mandelbrot Window");

	img.img = mlx_new_image(mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);

	// 描画
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 17, 0, on_close, NULL);
	// mlx_key_hookの第三引数で画像のアドレスを渡してあげれば別の関数で画像を編集出来たり、画像をウィンドウに乗せたりできる
	mlx_key_hook(mlx.win, on_key, NULL);
	mlx_loop(mlx.mlx);
}
