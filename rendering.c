/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:56:37 by moabed            #+#    #+#             */
/*   Updated: 2026/01/03 14:56:44 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
    return(new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min;
}

void    pixel_handling(int  x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;

    z.real = 0.0;
    z.imaginary = 0.0;

    c.real = scale(x, -2, 3, 0, WIDTH);
    c.imaginary = scale(y, 2, -2, 0, HEIGHT);
    
}
// void    fractal_render(t_fractal fractal)
// {
// }