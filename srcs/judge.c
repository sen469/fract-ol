/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:29:44 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:38:28 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	judge(t_fractol *fractol)
{
	if (fractol->data.fractal_type == MANDELBROT)
	{
		mandel_arr_init(fractol->fractal_values, &fractol->point);
		mandelbrot(&fractol->data, fractol->fractal_values);
	}
	else if (fractol->data.fractal_type == JULIA)
	{
		// julia();
	}
	else
	{}
}
