/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:18:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/12 16:18:27 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"


/*
int main()
{
	double	a, b;
	a = ft_atof("123e+2");
	b = ft_atof("00.0000001");
	printf("a = %.1e, b = %.10e\n", a, b);
	return (0);
}
*/

/*
int	main(int argc, char **argv)
{
	t_comp	input;

	if (argc <= 1 || argc >= 5)
	{
		write(1, "Argument Error\n", 15);
		return (0);
	}
	else if (!ft_strncmp(argv[1], "Mandelbrot", 10) || !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		mandelbrot();
	}
	(void)input;
	// input_init(&input, argv[2], argv[3]);
	return (0);
}
*/


int main()
{
	mandelbrot();
	return (0);
}
