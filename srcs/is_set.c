/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:40:33 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/25 13:06:48 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_set(char **av, t_data *d, int ac, t_comp *param)
{
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		d->fractal_type = MANDELBROT;
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		d->fractal_type = JULIA;
		param->re = ft_atof(av[2]);
		param->im = ft_atof(av[3]);
	}
	else if (ac == 2 && !ft_strcmp(av[1], "julia"))
		d->fractal_type = JULIA;
	else if (ac == 2 && !ft_strcmp(av[1], "burning_ship"))
		d->fractal_type = BURNING_SHIP;
	else
		return (0);
	return (1);
}
