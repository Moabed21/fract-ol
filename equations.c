/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:57:34 by moabed            #+#    #+#             */
/*   Updated: 2026/01/17 17:42:50 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_complex *z, t_complex *c)
{
	double	tmp_num;

	tmp_num = (z->real * z->real) - (z->imaginary * z->imaginary);
	z->imaginary = 2 * z->real * z->imaginary;
	z->real = tmp_num;
	z->real += c->real;
	z->imaginary += c->imaginary;
}

double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled) / (old_max) + new_min);
}

int	get_psychedelic_color(int i, t_fractal *fractal)
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
