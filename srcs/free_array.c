/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:37:40 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:39:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "struct.h"

void	free_array(t_fractol *fractol)
{
	int	i;
	t_val	**arr;

	arr = fractol->fractal_values;
	i = 0;
	while (i < HEIGHT)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i++;
	}
	mlx_destroy_image(fractol->data.mlx_ptr, fractol->data.img_ptr);
	mlx_destroy_window(fractol->data.mlx_ptr, fractol->data.win_ptr);
	mlx_destroy_display(fractol->data.mlx_ptr);
	free(fractol->data.mlx_ptr);
	free(arr);
}
