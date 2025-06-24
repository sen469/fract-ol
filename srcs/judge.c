/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:29:44 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/24 13:35:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
void	judge(t_fractol *fractol)
{
	if (fractol->data.fractal_type == MANDELBROT)
	{
		array_init(fractol->fractal_values, &fractol->point, fractol->data.fractal_type);
		draw(&fractol->data, fractol->fractal_values, &fractol->param);
	}
	else if (fractol->data.fractal_type == JULIA)
	{
		array_init(fractol->fractal_values, &fractol->point, fractol->data.fractal_type);
		draw(&fractol->data, fractol->fractal_values, &fractol->param);
	}
	else
	{}
}
*/
void	judge(t_fractol *fractol)
{
		array_init(fractol->fractal_values, &fractol->point, fractol->data.fractal_type);
		draw(&fractol->data, fractol->fractal_values, &fractol->param);
}
