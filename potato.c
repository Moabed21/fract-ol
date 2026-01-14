/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:44:02 by moabed            #+#    #+#             */
/*   Updated: 2026/01/15 01:38:12 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pixel_ptr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	malloc_fail(void)
{
	perror("Error allocating memory\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandlebrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if ((ac == 4 && !ft_strncmp(av[1], "julia", 5)))
		{
			fractal.j_real = atodbl(av[2]);
			fractal.j_imaginary = atodbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx(&fractal);
	}
	else
		ft_putstr_fd("Wrong inputs,try mandlebrot or julia real imaginary", 2);
}

double	atodbl(char *num)
{
	long	intpart;
	double	fracpart;
	double	pow;
	int		sign;

	intpart = 0;
	fracpart = 0;
	pow = 1;
	sign = 1;
	while ((*num >= 9 && *num <= 13) || *num == ' ')
		num++;
	if (*num == '-' || *num == '+')
		if (*num++ == '-')
			sign = sign * -1;
	while (*num != '.' && *num)
		intpart = (intpart * 10) + (*num++ - 48);
	if (*num == '.')
		num++;
	while (*num)
	{
		pow /= 10;
		fracpart = fracpart + (*num++ - 48) * pow;
	}
	fracpart = (fracpart + intpart) * sign;
	return (fracpart);
}
