/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:16:27 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 20:35:27 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

void	mandel_mapping(t_data *data, t_val arr[HEIGHT][WIDTH])
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	idx;
	unsigned int	color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			idx = data->line_len * i + j * (data->bpp / 8);
			color = get_psychedelic_color(&arr[i][j]);
			data->addr[idx] = color;
			j++;
		}
		i++;
	}
}
