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

static void	set_rgb_low_h(double h, double c, double x, double *rgb_d)
{
	if (h < 60)
	{
		rgb_d[0] = c;
		rgb_d[1] = x;
		rgb_d[2] = 0;
	}
	else if (h < 120)
	{
		rgb_d[0] = x;
		rgb_d[1] = c;
		rgb_d[2] = 0;
	}
	else
	{
		rgb_d[0] = 0;
		rgb_d[1] = c;
		rgb_d[2] = x;
	}
}

static void	set_rgb_high_h(double h, double c, double x, double *rgb_d)
{
	if (h < 240)
	{
		rgb_d[0] = 0;
		rgb_d[1] = x;
		rgb_d[2] = c;
	}
	else if (h < 300)
	{
		rgb_d[0] = x;
		rgb_d[1] = 0;
		rgb_d[2] = c;
	}
	else
	{
		rgb_d[0] = c;
		rgb_d[1] = 0;
		rgb_d[2] = x;
	}
}

unsigned int	hsv_to_rgb(double h, double s, double v)
{
	double			c;
	double			x;
	double			m;
	double			rgb_d[3];
	unsigned int	rgb_val[3];

	c = v * s;
	x = c * (1 - ft_fabs(ft_fmod(h / 60.0, 2) - 1));
	m = v - c;
	if (h < 180)
	{
		set_rgb_low_h(h, c, x, rgb_d);
	}
	else
	{
		set_rgb_high_h(h, c, x, rgb_d);
	}
	rgb_val[0] = (unsigned int)((rgb_d[0] + m) * 255);
	rgb_val[1] = (unsigned int)((rgb_d[1] + m) * 255);
	rgb_val[2] = (unsigned int)((rgb_d[2] + m) * 255);
	return ((rgb_val[0] << 16) | (rgb_val[1] << 8) | rgb_val[2]);
}

unsigned int	get_psychedelic_color(t_val *v, int endian)
{
	double			t;
	double			h;
	double			s;
	double			val;
	unsigned int	rgb;

	if (v->diverged == 0)
	{
		return (BLACK);
	}
	t = (double)v->cnt / 100;
	h = fmod(360.0 * t, 360.0);
	s = 1.0;
	val = 1.0;
	rgb = hsv_to_rgb(h, s, val);
	if (endian == 0)
	{
		return (rgb);
	}
	return (((rgb & 0xFF) << 16) | (rgb & 0xFF00) | ((rgb >> 16) & 0xFF));
}
