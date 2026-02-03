/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:57:34 by moabed            #+#    #+#             */
/*   Updated: 2026/02/04 00:03:46 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled) / (old_max) + new_min);
}

int	color_fun(int i, t_fractal *fractal)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / (double)fractal->init_iteration;
	r = (int)(15 * t * 200);
	g = (int)(10 * t * 255 / 2);
	b = (int)(25 * t * 80);
	return ((r << 16) | (g << 8) | b);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	data_init(fractal);
	if (fractal->mlx_connection == NULL)
		error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 5;
	fractal->init_iteration = 350;
	fractal->zoom = 1.05;
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixel_ptr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}
