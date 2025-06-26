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

int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

double	get_integer_part(const char **str)
{
	double	res;

	res = 0.0;
	while (ft_isdigit(**str))
		res = res * 10 + (*((*str)++) - '0');
	return (res);
}

double	get_decimal_part(const char **str)
{
	double	res;
	double	dec;

	res = 0.0;
	dec = 0.1;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			res += (*((*str)++) - '0') * dec;
			dec *= 0.1;
		}
	}
	return (res);
}

double	apply_exponent(const char **str, double res)
{
	int	exp;

	if (**str == 'e' || **str == 'E')
	{
		(*str)++;
		exp = ft_atoi(*str);
		while (exp < 0)
		{
			res /= 10;
			exp++;
		}
		while (exp > 0)
		{
			res *= 10;
			exp--;
		}
	}
	return (res);
}

double	ft_atof(const char *str)
{
	const char	*p;
	int			sign;
	double		res;

	p = str;
	sign = get_sign(&p);
	res = get_integer_part(&p);
	res += get_decimal_part(&p);
	res = apply_exponent(&p, res);
	return (sign * res);
}
