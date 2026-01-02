/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:44:02 by moabed            #+#    #+#             */
/*   Updated: 2026/01/02 23:39:03 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixel_ptr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	malloc_fail(void)
{
	perror("Error allocating memory\n");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if(fractal->mlx_connection == NULL)
		malloc_fail();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);	
	if(fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_fail();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if(fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection,fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_fail();
	}
	fractal->img.pixel_ptr=mlx_get_data_addr(fractal->img.img,
		&fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
}

int	main(int ac, char **av)
{
	t_fractal fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandlebrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
	}
	else
		ft_putstr_fd("Wrong inputs,try <mandlebrot>\n or \n<julia><real number> <imaginary number>",
			2);
}
// t_complex z;
// t_complex c;

// z.imaginary = 0;
// z.real = 0;
// c.real = 0.2;
// c.imaginary = 0.1;

// mandlebrot(z, c, 20);
//    void *mlx;
//    void *img_win;
//    t_data   img;
// int j = 50;
// int i = 50;
//     mlx = mlx_init();
//     img_win = mlx_new_window(mlx, 1920, 1080 , "prototype");
//     img.img = mlx_new_image(mlx, 1280, 720);
//     img.addr = mlx_get_data_addr(img.img,&img.bits_per_pixel,&img.line_length,&img.endian);

//     my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
//     mlx_put_image_to_window(mlx, img_win,img.img, 0, 0);
//     mlx_loop(mlx);
