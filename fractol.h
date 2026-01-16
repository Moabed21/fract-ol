/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:07:52 by moabed            #+#    #+#             */
/*   Updated: 2026/01/17 01:38:07 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# define WIDTH 1080
# define HEIGHT 1080

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
	int		init_iteration;
	void	*mlx_connection;
	void	*mlx_window;
	double	escape_value;
	double	zoom;
	double	j_real;
	double	j_imaginary;
	t_image	img;

}			t_fractal;

void		mandlebrot(t_complex *z, t_complex *c);
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		fractal_render(t_fractal *fractal);
void		mlx(t_fractal *fractal);
void		malloc_fail(void);
int			image_handler(t_fractal *fractal);
int			key_handler(int key, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			get_psychedelic_color(int i, t_fractal *fractal);
double		atodbl(char *num);
double		scale(double unscaled, double new_min, double new_max,
				double old_max);
#endif