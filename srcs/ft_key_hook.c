/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:27:52 by neprocur          #+#    #+#             */
/*   Updated: 2016/04/15 22:58:24 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		eat_sleep_rave_repeat(t_env *e)
{
	t_pt	start;
	double	angle;
	int		depth;

	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (e->av == 1)
		mandelbrot(e);
	if (e->av == 2)
		julia(e);
	if (e->av == 3)
		buddhabrot(e);
	if (e->av == 6)
	{
		start.x = 500;
		start.y = 500;
		angle = 0;
		depth = 6;
		pythagore_tree(e, start, angle, depth);
	}
}

int			funct(int x, int y, t_env *e)
{
	e->coord_x = (e->x_min + (e->x_max - e->x_min) * ((double)x / WIDTH));
	e->coord_y = (e->y_min + (e->y_max - e->y_min) * ((double)y / HEIGHT));
	eat_sleep_rave_repeat(e);
	return (0);
}

int			ft_mouse_hook(int event, int x, int y, t_env *e)
{
	double	tmp_a;
	double	tmp_b;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (0);
	tmp_a = e->x_max - e->x_min;
	tmp_b = e->y_max - e->y_min;
	if (event == UP)
	{
		e->x_min += (tmp_a / 20);
		e->x_max -= (tmp_a / 20);
		e->y_min += (tmp_b / 20);
		e->y_max -= (tmp_b / 20);
	}
	if (event == DOWN)
	{
		e->x_min -= (tmp_a / 20);
		e->x_max += (tmp_a / 20);
		e->y_min -= (tmp_b / 20);
		e->y_max += (tmp_b / 20);
	}
	eat_sleep_rave_repeat(e);
	return (0);
}

void		ft_key_hook2(int keycode, t_env *e, double *tmp_a, double *tmp_b)
{
	if (keycode == RIGHT)
	{
		e->x_min += (*tmp_a / 20);
		e->x_max += (*tmp_a / 20);
	}
	else if (keycode == LEFT)
	{
		e->x_max -= (*tmp_a / 20);
		e->x_min -= (*tmp_a / 20);
	}
	else if (keycode == MORE)
	{
		e->x_min += (*tmp_a / 20);
		e->x_max -= (*tmp_a / 20);
		e->y_min += (*tmp_b / 20);
		e->y_max -= (*tmp_b / 20);
	}
	else if (keycode == LESS)
	{
		e->x_min -= (*tmp_a / 20);
		e->x_max += (*tmp_a / 20);
		e->y_min -= (*tmp_b / 20);
		e->y_max += (*tmp_b / 20);
	}
}

int			ft_key_hook(int keycode, t_env *e)
{
	double	tmp_a;
	double	tmp_b;

	tmp_a = e->x_max - e->x_min;
	tmp_b = e->y_max - e->y_min;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == H)
	{
		e->y_min -= (tmp_b / 20);
		e->y_max -= (tmp_b / 20);
	}
	else if (keycode == I)
		e->it_max += 50;
	else if (keycode == B)
		e->it_max -= 50;
	else if (keycode == BAS)
	{
		e->y_min += (tmp_b / 20);
		e->y_max += (tmp_b / 20);
	}
	else
		ft_key_hook2(keycode, e, &tmp_a, &tmp_b);
	eat_sleep_rave_repeat(e);
	return (0);
}
