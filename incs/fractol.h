/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:26:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/12 16:17:59 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

# include "libft/libft.h"
# include <fcntl.h>
# include <errno.h>

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;


// main process
void	input_init(t_comp *input, char *re, char *im);





// utils
t_comp	comp_multiple(t_comp a, t_comp b);
double	ft_atof(const char *str);





#endif
