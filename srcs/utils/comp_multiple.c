/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_multiple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:40:45 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/12 16:17:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

t_comp	comp_multiple(t_comp a, t_comp b)
{
	t_comp	rtn;

	rtn.re = a.re * b.re - a.im * b.im;
	rtn.im = a.re * b.im + b.re * a.im;
	return (rtn);
}
