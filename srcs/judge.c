/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:29:44 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:38:28 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	judge(t_data *data, t_val arr[HEIGHT][WIDTH])
{
	printf("judge.c %d = data.set\n", data->set);
	if (data->set == MANDELBROT)
	{
		write(1, "sex3\n", 5);
		mandel_arr_init(arr, &data->point);
		mandelbrot(data, arr);
	}
	else if (data->set == JULIA)
	{
		// julia();
		printf("judge.c julia\n");
	}
	else
		printf("judge.c else");
}
