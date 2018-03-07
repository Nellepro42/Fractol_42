/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 19:46:37 by neprocur          #+#    #+#             */
/*   Updated: 2016/04/17 00:54:36 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		buddha_coord2(t_env *e, int i, double tmp, int *map)
{
	int		x;
	int		y;
	int		imax;

	if (i != e->it_max)
	{
		imax = i;
		i = -1;
		e->z_r = 0;
		e->z_i = 0;
		while (++i < imax)
		{
			tmp = e->z_r;
			x = (int)((e->z_r - e->x_min) / (e->x_max - e->x_min) * WIDTH);
			y = (int)((e->z_i - e->y_min) / (e->y_max - e->y_min) * HEIGHT);
			if (x * HEIGHT + y < WIDTH * HEIGHT && (e->z_r || e->z_i))
				++map[x * HEIGHT + y];
			e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
			e->z_i = 2 * e->z_i * tmp + e->c_i;
		}
	}
}

void		buddha_coord(int x, int y, t_env *e, int *map)
{
	int					i;
	double				tmp;

	e->c_r = ((double)x / (double)WIDTH) * (e->x_max - e->x_min) + e->x_min;
	e->c_i = ((double)y / (double)HEIGHT) * (e->y_max - e->y_min) + e->y_min;
	e->z_r = 0;
	e->z_i = 0;
	i = 0;
	while (i < e->it_max)
	{
		tmp = e->z_r;
		x = (int)((e->z_r - e->x_min) / (e->x_max - e->x_min) * WIDTH);
		y = (int)((e->z_i - e->y_min) / (e->y_max - e->y_min) * HEIGHT);
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		if ((e->z_r * e->z_r + e->z_i * e->z_i) > 4.0)
			break ;
		++i;
	}
	buddha_coord2(e, i, tmp, map);
}

void		buddhabrot2(t_env *e, int max, char *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			((int *)map)[x + y * WIDTH] = get_color(((int *)map)[x + y * WIDTH],
			max / 4);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void		buddhabrot(t_env *e)
{
	int		x;
	int		y;
	int		result;
	char	*map;
	int		max;

	coord_buddha2(e);
	map = mlx_get_data_addr(e->img, &result, &result, &result);
	y = -1;
	max = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			buddha_coord((double)x, (double)y, e, (int *)map);
	}
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			max = max > ((int *)map)[x + y * WIDTH] ? max :
			((int *)map)[x + y * WIDTH];
	}
	buddhabrot2(e, max, map);
}
