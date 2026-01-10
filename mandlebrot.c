/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:57:34 by moabed            #+#    #+#             */
/*   Updated: 2026/01/10 22:55:29 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandlebrot(t_complex *z, t_complex *c)
{
	double	tmp_num;

	tmp_num = (z->real * z->real) - (z->imaginary * z->imaginary);
	z->imaginary = 2 * z->real * z->imaginary;
	z->real = tmp_num;
	z->real += c->real;
	z->imaginary += c->imaginary;
}
