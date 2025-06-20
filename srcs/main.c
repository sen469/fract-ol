/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:42:12 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

int	on_key(int keycode, void *param)
{
	(void)param;
	printf("keycode = %d\n", keycode);
	if (keycode == ESC)
	{
		exit(0);
	}
	return (1);
}
int	main(int ac, char **av)
{
	int	flag;
	t_data	data;
	t_val	arr[HEIGHT][WIDTH];

	if (ac <= 1)
		return (0);
	flag = (ac == 4 && ft_strcmp(av[1], "julia"));
	if (flag)
	{
		return (0);
	}
	else if (is_set(av[1], &data))
	{
		mlx_setup(&data);
		judge(&data, arr);
		write(1, "sex\n", 4);
		printf("data.set = %d\n", data.set);
		// draw();
		// キー入力を受け取ったときにはmapを初期化する
		mlx_key_hook(data.win_ptr, on_key, NULL);
		// キー入力を受け取らない場合はマップを更新していく
		// mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
