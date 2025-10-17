/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:09:29 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/20 18:35:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	mlx_setup(t_data *d, char *fractal_name)
{
	int	i;

	i = 0;
	while (fractal_name[i])
	{
		fractal_name[i] = ft_toupper(fractal_name[i]);
		i++;
	}
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, fractal_name);
	d->img_ptr = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->line_len, &d->endian);
}
