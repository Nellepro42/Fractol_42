/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 19:40:23 by neprocur          #+#    #+#             */
/*   Updated: 2016/04/15 22:55:07 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia_init(t_env *e)
{
	e->x_min = -0.85;
	e->x_max = 1;
	e->y_min = -1;
	e->y_max = 1.2;
	e->it_max = 150;
}

int				julia_coord(double x, double y, t_env *e)
{
	int			i;
	static int	k = 0;
	double		tmp_r;

	i = 0;
	if (k == 0)
		julia_init(e);
	e->z_r = e->x_min + (e->x_max - e->x_min) * (x / (double)WIDTH);
	e->z_i = e->y_min + (e->y_max - e->y_min) * (y / (double)HEIGHT);
	while (i < e->it_max)
	{
		tmp_r = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->coord_x;
		e->z_i = 2 * e->z_i * tmp_r + e->coord_y;
		if ((e->z_r * e->z_r + e->z_i * e->z_i) > 4)
			return (0x330033 * cos((double)i));
		i++;
	}
	k = 1;
	return (0x660033);
}

void			julia(t_env *e)
{
	int			x;
	int			y;
	int			result;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if ((result = julia_coord((double)x, (double)y, e)) != 0)
				ft_mlx_pixel_img(e, x, y, result);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int				coord(double x, double y, t_env *e)
{
	int			i;

	x = e->x_min + (e->x_max - e->x_min) * (x / WIDTH);
	y = e->y_min + (e->y_max - e->y_min) * (y / HEIGHT);
	e->z_r = 0;
	e->z_i = 0;
	i = 0;
	while (i < e->it_max)
	{
		e->c_r = e->z_r;
		e->c_i = e->z_i;
		e->z_r = e->c_r * e->c_r - e->c_i * e->c_i + x;
		e->z_i = 2 * e->c_r * e->c_i + y;
		if ((e->z_r * e->z_r + e->z_i * e->z_i) > 4)
			return (0x330099 * cos((double)i));
		i++;
	}
	return (0x670099);
}

void			mandelbrot(t_env *e)
{
	int			x;
	int			y;
	int			result;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if ((result = coord((double)x, y, e)) != 0)
				ft_mlx_pixel_img(e, x, y, result);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
