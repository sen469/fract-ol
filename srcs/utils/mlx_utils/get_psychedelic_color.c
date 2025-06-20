/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_psychedelic_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:21:04 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:36:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/fractol.h"

unsigned int get_psychedelic_color(t_val *v)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)v->cnt / 100;
    // 周期的なカラー変化（波形っぽく）
	if (v->is_div)
	{
		r = (int)(sin(6.2831 * t * 3.0) * 127 + 128);
		g = (int)(sin(6.2831 * t * 5.0 + 2.0) * 127 + 128);
		b = (int)(sin(6.2831 * t * 7.0 + 4.0) * 127 + 128);
	}
	else
	{
		r = 0xff;
		g = 0xff;
		b = 0xff;
	}

    // 32bitカラーとしてまとめて返す（0xRRGGBB）
	return ((r << 16) | (g << 8) | b);
}
