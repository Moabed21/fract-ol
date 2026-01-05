/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:56:37 by moabed            #+#    #+#             */
/*   Updated: 2026/01/05 21:08:26 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double scale(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
    return(new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min;
}

static void    pixel_handling(int  x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    int i;
    int color;
    
    i = 0;
    z.real = 0.0;
    z.imaginary = 0.0;
    //pixel coordinate real & imaginary to fit mandlebrot needs
    c.real = scale(x, -2, 3, 0, WIDTH);
    c.imaginary = scale(y, 2, -2, 0, HEIGHT);
    while (i < fractal->init_iteration)
    {
        mandlebrot(&z, &c);
        if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->escape_value)
        {
            // معادلة لون بسيطة أفضل من الـ scale للألوان
            // هذا سيعطيك تدرجاً بناءً على عدد المحاولات
            color = scale(i,BLACK,WHITE,0,fractal->init_iteration); 
            // أو جرب لون ثابت للتأكد أولاً: 0xFFFFFF
            my_mlx_pixel_put(&fractal->img, x, y, color);
            return;
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->img,x ,y,MAGENTA);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            pixel_handling(x,y,fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection,fractal->mlx_window,fractal->img.img,0,0);
}