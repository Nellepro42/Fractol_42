/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 00:49:06 by neprocur          #+#    #+#             */
/*   Updated: 2016/03/21 04:52:08 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	coord_pythagore_tree(t_env *e, t_pt start, t_pt end)
{
	double	dd;
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = start.x;
	y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- >= 0)
	{
		if (x < 1000 && x > 0 && y > 0 && y < 1000)
			ft_mlx_pixel_img(e, x, y, 0xFFFFFF);
		x += dx;
		y += dy;
	}
}

void	pythagore_tree(t_env *e, t_pt start, double angle, int depth)
{
	double	x2;
	double	y2;
	int		tmp;
	t_pt	end;

	tmp = depth;
	if (depth > 0)
	{
		x2 = start.x + (cos(angle) * depth * 10);
		y2 = start.y + (sin(angle) * depth * 10.0);
		end.x = x2;
		end.y = y2;
		coord_pythagore_tree(e, start, end);
		depth = tmp;
		pythagore_tree(e, end, angle - (M_PI / 8), depth - 1);
		pythagore_tree(e, end, angle + (M_PI / 8), depth - 1);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
}
