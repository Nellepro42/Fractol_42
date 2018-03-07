/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 00:22:50 by neprocur          #+#    #+#             */
/*   Updated: 2016/03/12 06:42:01 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		coord_buddha2(t_env *e)
{
	e->x_min = -2;
	e->x_max = 2;
	e->y_min = -2;
	e->y_max = 2;
	e->it_max = 6000;
	e->zoom = 1;
}

int			get_color(int c, int max)
{
	int		color;

	color = (int)(15.0 * (double)c / (double)max);
	return (c ? (color << 16 / 4) + (color << 8 / 4) + color : 0 / 4);
}
