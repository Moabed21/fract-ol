/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:07:52 by moabed            #+#    #+#             */
/*   Updated: 2026/01/02 20:58:13 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <sys/time.h>
# define WIDTH 720
# define HEIGHT 720
typedef struct s_image
{
	void	*img;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window; 
	t_image	img;
} t_fractal;

//mandlebrot
void	mandlebrot(t_complex z, t_complex c, int i);


#endif