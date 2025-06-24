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

/* ========================================================================
unsigned int get_psychedelic_color(t_val *v, int endian)
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
	double	t;

	t = (double)v->cnt / 100;
	if (v->diverged)
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
============================================================================*/

unsigned int hsv_to_rgb(double h, double s, double v)
{
	double c = v * s;
	double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	double m = v - c;
	double r, g, b;

	if (h < 60)
		{ r = c; g = x; b = 0; }
	else if (h < 120)
		{ r = x; g = c; b = 0; }
	else if (h < 180)
		{ r = 0; g = c; b = x; }
	else if (h < 240)
		{ r = 0; g = x; b = c; }
	else if (h < 300)
		{ r = x; g = 0; b = c; }
	else
		{ r = c; g = 0; b = x; }

	unsigned int R = (unsigned int)((r + m) * 255);
	unsigned int G = (unsigned int)((g + m) * 255);
	unsigned int B = (unsigned int)((b + m) * 255);
	return (R << 16 | G << 8 | B);
}

unsigned int get_psychedelic_color(t_val *v, int endian)
{
	double			t;
	double			h;
	double			s;
	double			val;
	unsigned int	rgb;

	if (v->diverged == 0)
		return (BLACK);
	t = (double)v->cnt / 100;
	h = fmod(360.0 * t, 360.0);
	s = 1.0;
	val = 1.0;
	rgb = hsv_to_rgb(h, s, val);
	if (endian == 0)
		return rgb;
	else
		return ((rgb & 0xFF) << 16) | (rgb & 0xFF00) | ((rgb >> 16) & 0xFF);
}
