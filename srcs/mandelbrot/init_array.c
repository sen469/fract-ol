/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:45:10 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/18 22:48:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

void	init_array(t_val ***arr, t_point *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			p->pixel = 3.0 / 200 / p->zoom;
			i = HEIGHT - i;
			arr[i][j]->pos.re = p->sta.re + i * p->pixel;
			arr[i][j]->pos.im = p->sta.im + j * p->pixel;
			arr[i][j]->pre.re = 0;
			arr[i][j]->pre.im = 0;
		}
	}
}
