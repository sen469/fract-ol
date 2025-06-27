/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:26:30 by ssawa             #+#    #+#             */
/*   Updated: 2025/06/27 15:54:33 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* ========================== */
/*         Includes           */
/* ========================== */
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "struct.h"
// # include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

/* ========================== */
/*         Constants          */
/* ========================== */
# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

# define MAX_ITER 60

// # define ESC 65307
// # define RIGHT 65363
// # define UP 65362
// # define DOWN 65364
// # define LEFT 65361

# define CLICK 1
# define RIGHT_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// Mac 用（必要に応じて有効化）
# define ESC 53
# define RIGHT 124
# define UP 125
# define DOWN 126
# define LEFT 123

/* ========================== */
/*         Prototypes         */
/* ========================== */

/* ---------- Init / Setup ---------- */
int				is_set(char **s, t_data *d, int ac, t_comp *param);
void			mlx_setup(t_data *d);
void			point_init(t_point *point);
void			array_init(t_val **arr, t_point *point, int type);

/* ---------- Fractal Drawing ---------- */
void			judge(t_fractol *fractol);
void			draw(t_data *data, t_val **arr, t_comp *param);
void			mapping(t_data *data, t_val **arr, int endian);

/* ---------- Input Handling ---------- */
int				on_key(int keycode, void *param);
int				on_scroll(int button, int x, int y, void *param);
int				on_close(void *param);
void			zoom(int x, int y, t_fractol *fractol);
void			skip(int x, int y, t_point *point);
int				is_keycode(int keycode);
int				on_mouse_move(int x, int y, void *param);
int	loop_update(void *param);

/* ---------- Complex Number Utils ---------- */
t_comp			comp_multiple(t_comp a, t_comp b);
t_comp			comp_multiple_burning_ship(t_comp z);
t_comp			comp_add(t_comp a, t_comp b);
double			comp_abs(t_comp val);

/* ---------- Misc Utilities ---------- */
double			ft_atof(const char *str);
unsigned int	get_psychedelic_color(t_val *v, int endian);
void			free_array(t_val **arr);
t_val			**malloc_array(void);
void			free_array(t_val **arr);

#endif
