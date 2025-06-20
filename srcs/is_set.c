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

#include "../incs/fractol.h"

int	is_set(char *s, t_data *d)
{
	if (!ft_strcmp(s, "mandelbrot"))
	{
		printf("before d.set %d\n", d->set);
		d->set = MANDELBROT;
		printf("after d.set %d\n", d->set);
		return (1);
	}
	else if (!ft_strcmp(s, "julia"))
	{
		d->set = JULIA;
		return (1);
	}
	return (0);
}
