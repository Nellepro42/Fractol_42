/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neprocur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 21:33:52 by neprocur          #+#    #+#             */
/*   Updated: 2016/04/22 23:57:24 by neprocur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_choose(t_env *e)
{
	t_pt			start;
	double			angle;
	int				depth;

	if (e->av == 1)
		mandelbrot(e);
	else if (e->av == 2)
		julia(e);
	else if (e->av == 3)
		buddhabrot(e);
	else if (e->av == 4)
		anti_buddha(e);
	else if (e->av == 5)
	{
		start.x = 500;
		start.y = 500;
		angle = -M_PI / 2;
		depth = 9;
		pythagore_tree(e, start, angle, depth);
	}
}

int					ft_which(t_env *e, char **av)
{
	if (ft_strequ(av[1], "Mandelbrot") == 1)
		e->av = 1;
	else if (ft_strequ(av[1], "Julia") == 1)
		e->av = 2;
	else if (ft_strequ(av[1], "Buddhabrot") == 1)
		e->av = 3;
	else if (ft_strequ(av[1], "Antibuddha") == 1)
		e->av = 4;
	else if (ft_strequ(av[1], "Pytha_tree") == 1)
		e->av = 5;
	else
		return (-1);
	return (0);
}

t_env				*ft_init(void)
{
	t_env			*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	e->x = 0;
	e->y = 0;
	e->x_min = -2;
	e->x_max = 1;
	e->y_min = -1.5;
	e->y_max = 1.5;
	e->it_max = 50;
	return (e);
}

int					ft_exit(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	exit(EXIT_SUCCESS);
	return (0);
}

int					main(int ac, char **av)
{
	t_env			*e;

	if (ac == 2)
	{
		if ((e = ft_init()) == NULL || ft_which(e, av) == -1)
			return (EXIT_FAILURE);
		if ((e->mlx = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fractol");
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		ft_choose(e);
		mlx_mouse_hook(e->win, ft_mouse_hook, e);
		mlx_key_hook(e->win, ft_key_hook, e);
		mlx_hook(e->win, 17, 0, ft_exit, NULL);
		mlx_hook(e->win, 6, 1L << 6, funct, e);
		ft_mlx_pixel_img(e, 200, 200, 0x00FFFFFF);
		mlx_loop(e->mlx);
	}
	else
		ft_putendl("Usage -Mandelbrot -Julia -Buddhabrot -Antibuddha\
				-Pytha_tree");
	return (EXIT_SUCCESS);
}
