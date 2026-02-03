/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:44:02 by moabed            #+#    #+#             */
/*   Updated: 2026/02/04 00:27:21 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	valid(char *s)
{
	int	dots;
	int	has_digit;

	dots = 0;
	has_digit = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
			has_digit = 1;
		else if (*s == '.')
		{
			if (dots > 0)
				return (0);
			dots++;
		}
		else
			return (0);
		s++;
	}
	return (has_digit);
}

static double	dbl(char *num)
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

void	mprocessing(char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	fractal->type = 1;
	mlx(fractal);
}

void	jprocessing(char **av, t_fractal *fractal)
{
	int		v1;
	int		v2;
	double	arg2;
	double	arg3;

	v1 = valid(av[2]);
	v2 = valid(av[3]);
	arg2 = dbl(av[2]);
	arg3 = dbl(av[3]);
	fractal->type = 2;
	fractal->name = av[1];
	if ((v1 && (arg2 <= 2 && arg2 >= -2)) || (v2 && (arg3 <= 2 && arg3 >= -2)))
	{
		fractal->j.real = dbl(av[2]);
		fractal->j.imaginary = dbl(av[3]);
	}
	else
	{
		write(2, "Wrong inputs\n", 14);
		exit(EXIT_FAILURE);
	}
	mlx(fractal);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
		mprocessing(av, &fractal);
	else if ((ac == 4 && !ft_strncmp(av[1], "Julia", 5)))
		jprocessing(av, &fractal);
	else
		ft_putstr_fd("Bad inputs,try Mandelbrot or Julia <real> <imaginary>",
			2);
	return (0);
}
