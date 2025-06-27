/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:38:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:53:28 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "struct.h"

int	on_close(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	free_array(fractol);
	exit(0);
	return (0);
}
