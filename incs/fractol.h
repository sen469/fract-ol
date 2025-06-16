/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:26:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/16 22:07:23 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

# include "libft/libft.h"
# include "mlx/mlx.h"
#include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*addr;
	void	*img;
}	t_mlx;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// main process
void	input_init(t_comp *input, char *re, char *im);





// utils
t_comp	comp_multiple(t_comp a, t_comp b);
double	ft_atof(const char *str);

// mandelbrot
void	mandelbrot(void);




#endif
