/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_multiple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:40:45 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 19:53:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	comp_multiple(t_comp a, t_comp b)
{
	t_comp	ret;

	ret.re = a.re * b.re - a.im * b.im;
	ret.im = a.re * b.im + b.re * a.im;
	return (ret);
}

t_comp	comp_multiple_burning_ship(t_comp z)
{
	t_comp	ret;

	ret.re = z.re * z.re - z.im * z.im;
	ret.im = 2 * ft_fabs(z.re) * ft_fabs((z.im));
	return (ret);
}
