/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:56:37 by moabed            #+#    #+#             */
/*   Updated: 2026/02/04 00:27:31 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot_calc(t_complex *c, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	double		sreal;
	double		simag;

	z.real = 0.0;
	z.imaginary = 0.0;
	i = 0;
	while (i < fractal->init_iteration)
	{
		sreal = z.real * z.real;
		simag = z.imaginary * z.imaginary;
		if (sreal + simag > fractal->escape_value)
			return (i);
		z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
		z.real = sreal - simag + c->real;
		i++;
	}
	return (i);
}

static int	julia_calc(t_complex *z, t_fractal *fractal)
{
	double		sreal;
	double		simag;
	int			i;
	t_complex	c;

	c = fractal->j;
	i = 0;
	while (i < fractal->init_iteration)
	{
		sreal = z->real * z->real;
		simag = z->imaginary * z->imaginary;
		if (sreal + simag > fractal->escape_value)
			return (i);
		z->imaginary = 2 * z->real * z->imaginary + c.imaginary;
		z->real = sreal - simag + c.real;
		i++;
	}
	return (i);
}

static void	pixel_handling(int x, int y, t_fractal *fractal)
{
	int			i;
	int			color;
	t_complex	coords;

	coords.real = (scale(x, -2, 2, WIDTH) * fractal->zoom);
	coords.imaginary = (scale(y, 2, -2, HEIGHT) * fractal->zoom);
	if (fractal->type == 2)
		i = julia_calc(&coords, fractal);
	else
		i = mandelbrot_calc(&coords, fractal);
	if (i == fractal->init_iteration)
		color = 0x000000;
	else
		color = color_fun(i, fractal);
	my_mlx_pixel_put(&fractal->img, x, y, color);
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

void	error(void)
{
	perror("allocating memory failed\n");
	exit(EXIT_FAILURE);
}
