/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:19:27 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/17 19:34:25 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "struct.h"

void	point_init(t_point *point)
{
	point->zoom = 0.5;
	point->pixel = 3.0 / HEIGHT / point->zoom;
	point->draw_start.re = -(WIDTH / 2.0) * point->pixel;
	point->draw_start.im = -(HEIGHT / 2.0) * point->pixel;
}
