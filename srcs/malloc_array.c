/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:40:31 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:48:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_val	**malloc_array(void)
{
	int	i;
	t_val	**res;

	res = (t_val **)ft_calloc(HEIGHT, sizeof(t_val *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < HEIGHT)
	{
		res[i] = (t_val *)ft_calloc(WIDTH, sizeof(t_val));
		if (res[i] == NULL)
		{
			while (--i >= 0)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
