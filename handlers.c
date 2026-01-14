/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:50:57 by moabed            #+#    #+#             */
/*   Updated: 2026/01/14 17:55:49 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
    if (button == Button4)
        fractal->zoom *= 0.95; 
	else if (button == Button5)
        fractal->zoom *= 1.05;
    fractal_render(fractal);
    return (0);
}
int	image_handler(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img, 0, 0);
	return (0);
}

int	key_handler(int key, t_fractal *fractal)
{
	if (key == XK_Escape)
		close_handler(fractal);
	if (key == Button5)
	{
		fractal->zoom *= 0.95;
		fractal_render (fractal);
	}
	else if (key == Button4)
	{
		fractal->zoom *= 1.05;
		fractal_render (fractal);
	}
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
	return (0);
}

void	mlx(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_loop_hook(fractal->mlx_connection, image_handler, fractal);
	mlx_loop(fractal->mlx_connection);
}
