#include "fractol.h"

t_val	**malloc_arr(void)
{
	t_val	**arr;
	int	i;

	i = 0;
	arr = (t_val **)ft_calloc(HEIGHT,sizeof(t_val *));
	if (arr == NULL)
	{
		write(1, "Allocate Error\n", 16);
		exit(0);
	}
	while (i < HEIGHT)
	{
		arr[i] = (t_val *)ft_calloc(WIDTH, sizeof(t_val *));
		if (arr[i] == NULL)
		{
			while (i-- > 0)
			{
				free(arr[i]);
			}
			free(arr);
			write(1, "Allocate Error\n", 16);
			exit(0);
		}
		i++;
	}
	write(1, "malloc arr ok\n", 20);
	return (arr);
}
