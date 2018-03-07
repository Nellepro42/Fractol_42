/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 23:58:25 by neprocur          #+#    #+#             */
/*   Updated: 2016/03/21 03:46:13 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					coord_anti_buddha2(int *intmp, t_env *e, int *map)
{
	int					i;
	int					imax;
	double				tmp;

	i = -1;
	imax = intmp[2];
	e->z_r = 0;
	e->z_i = 0;
	while (++i < imax)
	{
		tmp = e->z_r;
		intmp[0] = (int)((e->z_r - e->x_min) / (e->x_max - e->x_min) * 1000);
		intmp[1] = (int)((e->z_i - e->y_min) / (e->y_max - e->y_min) * 1000);
		if (intmp[0] * HEIGHT + intmp[1] < WIDTH * HEIGHT && (e->z_r || e->z_i))
			++map[intmp[0] * HEIGHT + intmp[1]];
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
	}
}

void					coord_anti_buddha(int x, int y, t_env *e, int *map)
{
	int					i;
	double				tmp;
	int					intmp[3];

	e->c_r = ((double)x / (double)WIDTH) * (e->x_max - e->x_min) + e->x_min;
	e->c_i = ((double)y / (double)HEIGHT) * (e->y_max - e->y_min) + e->y_min;
	e->z_r = 0;
	e->z_i = 0;
	i = -1;
	while (++i < e->it_max)
	{
		tmp = e->z_r;
		x = (int)((e->z_r - e->x_min) / (e->x_max - e->x_min) * WIDTH);
		y = (int)((e->z_i - e->y_min) / (e->y_max - e->y_min) * HEIGHT);
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		if ((e->z_r * e->z_r + e->z_i * e->z_i) > 4.0)
			break ;
	}
	intmp[0] = x;
	intmp[1] = y;
	intmp[2] = i;
	coord_anti_buddha2(intmp, e, map);
}

void					anti_buddha2(t_env *e, char *map, int max)
{
	int					x;
	int					y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			((int *)map)[x + y * WIDTH] =
			get_color(((int *)map)[x + y * WIDTH], max / 4);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void					anti_buddha(t_env *e)
{
	int					x;
	int					y;
	int					result;
	char				*map;
	int					max;

	coord_buddha2(e);
	map = mlx_get_data_addr(e->img, &result, &result, &result);
	y = -1;
	max = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			coord_anti_buddha((double)x, (double)y, e, (int *)map);
	}
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			max = max > ((int *)map)[x + y * WIDTH] ? max : ((int *)map)[x + y
			* WIDTH];
	}
	anti_buddha2(e, map, max);
}
