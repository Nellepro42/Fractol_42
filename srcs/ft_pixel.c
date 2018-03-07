/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 19:50:34 by neprocur          #+#    #+#             */
/*   Updated: 2016/04/14 23:44:55 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mlx_pixel_img(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*pixel;

	if (x >= WIDTH || y >= HEIGHT || y < 0 || x < 0)
		return (0);
	new_color = mlx_get_color_value(e->mlx, color);
	pixel = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
	pixel[y * sizeline + (bpp / 8) * x] = (new_color & 0xFF);
	pixel[y * sizeline + (bpp / 8) * x + 1] = (new_color & 0xFF00) >> 8;
	pixel[y * sizeline + (bpp / 8) * x + 2] = (new_color & 0xFF0000) >> 16;
	return (0);
}
