/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:57:34 by moabed            #+#    #+#             */
/*   Updated: 2026/01/02 20:57:52 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandlebrot(t_complex z, t_complex c, int i)
{
	double	tmp_num;

	while (i--)
	{
		tmp_num = (z.real * z.real) - (z.imaginary * z.imaginary);
		z.imaginary = 2 * z.real * z.imaginary;
		z.real = tmp_num;
		z.real += c.real;
		z.imaginary += c.imaginary;
		printf("iteration : %d , real: %f imaginary: %f \n", i + 1, z.real,
			z.imaginary);
	}
}