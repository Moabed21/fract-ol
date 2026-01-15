/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:56:37 by moabed            #+#    #+#             */
/*   Updated: 2026/01/15 07:09:54 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	scale(double unscaled, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}

static int	get_psychedelic_color(int i, t_fractal *fractal)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / (double)fractal->init_iteration;
	r = (int)(5 * t  * 20);
	g = (int)(10 * t * 40);
	b = (int)(25 * t * 80);
	return ((r << 16) | (g << 8) | b);
}

void	julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
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
	c.real = (scale(x, -2, 2, 0, WIDTH) * fractal->zoom);
	c.imaginary = (scale(y, 2, -2, 0, HEIGHT) * fractal->zoom);
	julia(&z, &c, fractal);
	while (i <= fractal->init_iteration)
	{
		mandlebrot(&z, &c);
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
