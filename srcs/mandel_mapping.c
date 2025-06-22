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

#include "fractol.h"

void	mandel_mapping(t_data *data, t_val arr[HEIGHT][WIDTH], int endian)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	color;
	unsigned int	*pixels;

	pixels = (unsigned int *)data->addr;
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			color = get_psychedelic_color(&arr[i][j], endian);
			pixels[i * (data->line_len / 4) + j] = color;
			j++;
		}
		i++;
	}
}
