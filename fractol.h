/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:07:52 by moabed            #+#    #+#             */
/*   Updated: 2026/02/03 23:31:21 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <sys/time.h>
# define WIDTH 1080
# define HEIGHT 1080

typedef struct s_image
{
	void		*img;
	char		*pixel_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	int			type;
	int			init_iteration;
	void		*mlx_connection;
	void		*mlx_window;
	double		escape_value;
	double		zoom;
	t_complex	j;
	t_image		img;
}				t_fractal;

void			fractal_init(t_fractal *fractal);
void			data_init(t_fractal *fractal);
void			my_mlx_pixel_put(t_image *data, int x, int y, int color);
void			fractal_render(t_fractal *fractal);
void			mlx(t_fractal *fractal);
void			error(void);
int				image_handler(t_fractal *fractal);
int				key_handler(int key, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				color_fun(int i, t_fractal *fractal);
double			scale(double unscaled, double new_min, double new_max,
					double old_max);
#endif