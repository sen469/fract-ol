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

#include "fractol.h"

unsigned int get_psychedelic_color(t_val *v, int endian)
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
	double	t;

	t = (double)v->cnt / 100;
	if (v->is_div)
	{
		r = (int)(sin(6.2831 * t * 3.0) * 127 + 128);
		g = (int)(sin(6.2831 * t * 5.0 + 2.0) * 127 + 128);
		b = (int)(sin(6.2831 * t * 7.0 + 4.0) * 127 + 128);
	}
	else
		return (BLACK);

	if (endian == 0)
		return ((r << 16) | (g << 8) | b);
	else
		return ((b << 16) | (g << 8) | r);
}
