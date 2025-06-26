/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_scroll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:51:45 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/25 13:02:25 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_scroll(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->need_redraw = 1;
	if (button == SCROLL_UP)
	{
		fractol->point.zoom *= 1.1;
		zoom(x, y, fractol);
	}
	else if (button == SCROLL_DOWN)
	{
		fractol->point.zoom *= 0.9;
		zoom(x, y, fractol);
	}
	else if (button == CLICK)
		skip(x, y, &fractol->point);
	else if (button == RIGHT_CLICK)
		fractol->move ^= 1;
	else
	{
		fractol->need_redraw = 0;
		return (0);
	}
	return (0);
}
