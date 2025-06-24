/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:40:33 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 18:09:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../incs/fractol.h"
#include "fractol.h"
#include "libft.h"

int	is_set(char **av, t_data *d, int ac, t_comp *param)
{
	if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		d->fractal_type = JULIA;
		param->re = ft_atof(av[2]);
		param->im = ft_atof(av[3]);
		printf("param->re = %.4e, param->im = %.4e\n", param->re, param->im);
	}
	else if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		d->fractal_type = MANDELBROT;
		// return (1);
	}
	else if (ac == 2 && !ft_strcmp(av[1], "julia"))
	{
		d->fractal_type = JULIA;
		// param->re = 0.0;
		// param->im = 0.0;
		param->re = -0.742;
		param->im = 0.1;
		// return (1);
	}
	else
	{
		return (0);
	}
	return (1);
}
