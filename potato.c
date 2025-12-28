/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:44:02 by moabed            #+#    #+#             */
/*   Updated: 2025/12/28 18:43:53 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int main(void)
{
   void *mlx;
   void *img_win;
   t_data   img;
int j = 50;
int i = 50;
    mlx = mlx_init();
    img_win = mlx_new_window(mlx, 1920, 1080 , "prototype");
    img.img = mlx_new_image(mlx, 1280, 720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while()
    {
        
    }
    my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
    mlx_put_image_to_window(mlx, img_win,img.img, 0, 0);
    mlx_loop(mlx);
}