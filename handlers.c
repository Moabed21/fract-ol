/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:50:57 by moabed            #+#    #+#             */
/*   Updated: 2026/01/12 16:59:05 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
	return(0);
}

int		key_handler(int key, t_fractal *fractal)
{
	if(key == XK_Escape)
		close_handler(fractal);
	// else if(key == XK_Left)
	// 	fractal->real_shift += 0.5;
	// else if(key == XK_Right)
	// 	fractal->real_shift -= 0.5;
	// else if(key == XK_Up)
	// 	fractal->i_shift += 0.5;
	// else if(key == XK_Down)
	// 	fractal->i_shift -= 0.5;
	// else if(key == XK_plus || key == XK_equal || key == XK_KP_Add)
	// 	fractal->init_iteration +=10;
	// else if(key == XK_minus)
	// 	fractal->init_iteration -=10;
	// fractal_render(fractal);
	// mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
	return(0);
}

int	image_handler(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img, 0, 0);
	return (0);
}
int		mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if(button == Button5)
	{
		
	}
	if(button == Button5)
	{
		
	}
	
}
void	mlx(t_fractal *fractal)
{
	events_init(fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
	mlx_loop_hook(fractal->mlx_connection, image_handler, fractal);
	mlx_loop(fractal->mlx_connection);
}
