/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:56:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/25 13:04:40 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "struct.h"

int	on_mouse_move(int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (fractol->move && fractol->data.fractal_type == JULIA)
	{
		fractol->param = fractol->fractal_values[x][y].pos;
		fractol->need_redraw = 1;
	}
	return (0);
}
