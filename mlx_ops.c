/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 23:50:57 by moabed            #+#    #+#             */
/*   Updated: 2026/01/11 02:07:22 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	return(0);
}
int	image_consistency(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img, 0, 0);
	return (0);
}
void	mlx(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 17, 0, close_handler, fractal);
	mlx_loop_hook(fractal->mlx_connection, image_consistency, fractal);
	mlx_loop(fractal->mlx_connection);
}
