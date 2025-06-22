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

// #include "../incs/fractol.h"
#include "fractol.h"

void	judge(t_data *data, t_val **arr)
{
	if (data->set == MANDELBROT)
	{
		mandel_arr_init(arr, &data->point);
		mandelbrot(data, arr);
	}
	else if (data->set == JULIA)
	{
		// julia();
	}
	else
	{}
}
