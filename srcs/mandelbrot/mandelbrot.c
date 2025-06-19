/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:34:09 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/19 15:41:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

int	on_close(void *param)
{
	(void)param;
	exit(0);
}

int	on_key(int keycode, t_all *all)
{
	t_val	arr[WIDTH][HEIGHT];

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
		make_mandelbrot(&all->point, &all->data);
		// なんの入力も受け取らない
		// ここで計算する
	}
	// imageをウィンドウに表示する
	return (0);
}

void	mandelbrot(void)
{
	t_all	all;

	write(1, "ok", 2);
	all.data.mlx = mlx_init();
	all.data.win = mlx_new_window(all.data.mlx, WIDTH, HEIGHT, "Mandelbrot Window");

	// イメージの大きさを設定
	write(1, "ok", 2);
	all.data.img = mlx_new_image(all.data.mlx, 800, 600);
	// イメージのアドレスの設定、その他のall.dataのメンバを初期設定
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_len, &all.data.endian);

	write(1, "ok", 2);
	// 描画
	// imageをWindowの上に置く
	mlx_put_image_to_window(all.data.mlx, all.data.win, all.data.img, 0, 0);
	// mlx_loopの周回部分、もしばつ印を推したら終了
	mlx_hook(all.data.win, 17, 0, on_close, NULL);

	write(1, "ok", 2);
	// mlx_key_hookの第三引数で画像のアドレスを渡してあげれば別の関数で画像を編集出来たり、画像をウィンドウに乗せたりできる
	// loop の一部である、キー入力を待つ
	mlx_key_hook(all.data.win, on_key, &all);
	mlx_loop(all.data.mlx);
}
