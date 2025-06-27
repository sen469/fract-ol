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

void	free_array(t_val **arr)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i++;
	}
	free(arr);
}
