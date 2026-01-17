/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:56:37 by moabed            #+#    #+#             */
/*   Updated: 2026/01/17 18:08:20 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "Julia", 5))
	{
		z->real = c->real;
		z->imaginary = c->imaginary;
		c->real = fractal->j_real;
		c->imaginary = fractal->j_imaginary;
	}
}

static void	pixel_handling(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = 0;
	z.imaginary = 0;
	c.real = (scale(x, -2, 2, WIDTH) * fractal->zoom);
	c.imaginary = (scale(y, 2, -2, HEIGHT) * fractal->zoom);
	julia(&z, &c, fractal);
	while (i < fractal->init_iteration)
	{
		mandelbrot(&z, &c);
		if ((z.real * z.real) + (z.imaginary
				* z.imaginary) > fractal->escape_value)
		{
			color = get_psychedelic_color(i, fractal);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0x000000);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_handling(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img, 0, 0);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	data_init(fractal);
	if (fractal->mlx_connection == NULL)
		malloc_fail();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_fail();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_fail();
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
