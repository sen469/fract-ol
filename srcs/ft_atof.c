/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:50:55 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/19 21:26:21 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	i;
	double	res;

	i = 0.1;
	res = ft_atoi(str);
	while (*str != '.')
		str++;
	if (*str == '.')
	{
		while (ft_isdigit(*(++str)))
		{
			res += ((*str) - '0') * i;
			i /= 10;
		}
	}
	else if (*str == 'e' || *str == 'E')
	{
		i = ft_atoi(++str);
		if (i < 0)
		{
			while (i++)
				res /= 10;
		}
		else
		{
			// else がいらない説ある
			while (i--)
				res *= 10;
		}
	}
	return (res);
}
