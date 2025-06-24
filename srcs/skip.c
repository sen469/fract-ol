/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:51:00 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/24 18:54:41 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	skip(int x, int y, t_point *point)
{
	point->pixel = (3.0 / WIDTH) / point->zoom;
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	point->draw_start.re += point->pixel * x;
	point->draw_start.im += point->pixel * y;
	printf("%.5e, %.5e\n", point->draw_start.re, point->draw_start.im);
}
