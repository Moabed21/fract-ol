/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:56:37 by moabed            #+#    #+#             */
/*   Updated: 2026/01/12 16:34:53 by moabed           ###   ########.fr       */
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
	double t;
    int r;
    int g;
    int b;

    t = (double)i / (double)fractal->init_iteration;

    r = (int)(9 *  t * t  * 255);
    
    g = (int)(15 *  t *  255);
    
    b = (int)(8.5 * t*  255);

    return ((r << 16) | (g << 8) | b);
}

static void	pixel_handling(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = 0.0;
	z.imaginary = 0.0;
	// pixel coordinate real & imaginary to fit mandlebrot needs
	c.real = scale(x, -2, 2, 100, WIDTH) + fractal->real_shift;
	c.imaginary = scale(y, 2, -2, 100, HEIGHT) + fractal->i_shift;
	while (i < fractal->init_iteration)
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
}

void	fractal_render(t_fractal *fractal)
{
	int x;
	int y;

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
