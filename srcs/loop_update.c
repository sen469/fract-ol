/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:31:20 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:31:54 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_update(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->need_redraw)
	{
		array_init(fractol->fractal_values, &fractol->point, \
				fractol->data.fractal_type);
		fractol->need_redraw = 0;
	}
	draw(&fractol->data, fractol->fractal_values, &fractol->param);
	return (0);
}

