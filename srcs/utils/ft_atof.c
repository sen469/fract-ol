/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:50:55 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/12 16:17:24 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fractol.h"

/*
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
*/

double	ft_atof(const char *str)
{
	double	res;
	int		flag;
	int		ten;
	int		i;

	res = 0;
	i = 0;
	flag = 1;
	ten = 1;
	while (str[i])
	{
		if (str[i] == '.')
			flag = 0;
		else if (!ft_isdigit(str[i]))
			continue;
		else if (flag)
			res = res * 10 + (str[i] - '0');
		else
		{
			ten *= 10;
			res = res + ((double)(str[i] - '0') / ten);
		}
		i++;
	}
	return (res);
}

/*
#include <stdio.h>
int main()
{
	printf("%f, %f\n", ft_atof("123"), ft_atof("0000.0001"));
}
*/
