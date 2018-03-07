/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 19:29:34 by neprocur          #+#    #+#             */
/*   Updated: 2016/04/16 23:31:56 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>

# define WIDTH		1000
# define HEIGHT		1000
# define ESC		53
# define LEFT		123
# define RIGHT		124
# define H			126
# define BAS		125
# define IT_MAX		50
# define I			34
# define B			11
# define MORE		69
# define LESS		78
# define UP			5
# define DOWN		4

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					av;
	int					x;
	int					y;
	int					it_max;
	char				*max;
	int					result;
	char				*map;
	double				coord_x;
	double				coord_y;
	double				x_min;
	double				x_max;
	double				y_min;
	double				y_max;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				zoom;
}						t_env;

typedef struct			s_coord
{
	float				x;
	float				y;
}						t_coord;

typedef struct			s_pt
{
	int					x;
	int					y;
}						t_pt;

void					mandelbrot(t_env *e);
int						ft_mlx_pixel_img(t_env *e, int x, int y, int color);
void					julia(t_env *e);
void					buddhabrot(t_env *e);
void					anti_buddha(t_env *e);
void					pythagore_tree(t_env *e, t_pt start, double angle,
						int depth);
int						ft_mouse_hook(int event, int x, int y, t_env *e);
int						funct(int x, int y, t_env *e);
int						ft_mlx_image_pixel_put(t_env *e, int x, int y,
						int color);
int						coord(double x, double y, t_env *e);
int						get_color(int c, int max);
void					coord_buddha2(t_env *e);
int						ft_key_hook(int keycode, t_env *e);

#endif
