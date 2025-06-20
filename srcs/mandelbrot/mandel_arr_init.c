/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_arr_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:28:57 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:50:25 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

void	mandel_arr_init(t_val arr[HEIGHT][WIDTH], t_point *point)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			arr[i][j].cnt = 0;
			arr[i][j].pre.re = 0;
			arr[i][j].pre.im = 0;
			arr[i][j].pos.re = point->str_abs.re +  point->pixel * j;
			arr[i][j].pos.im = point->str_abs.im +  point->pixel * (HEIGHT - i - 1);
			j++;
		}
		i++;
	}
}
