/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/22 16:38:01 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int ac, char **av)
{
	int	flag;
	t_data	data;
	t_val	**arr = malloc_arr();

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
		mlx_setup(&data);
		mandel_point_init(&data.point);
		mlx_setup(&data);
		judge(&data, arr);
		mlx_setup(&data);
		// キー入力を受け取ったときにはmapを初期化する
		mlx_key_hook(data.win_ptr, on_key, &data);
		// キー入力を受け取らない場合はマップを更新していく
		// mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
		mlx_setup(&data);
		mlx_loop(data.mlx_ptr);
	}
	free_arr(arr);
	return (0);
}
