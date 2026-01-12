/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:07:52 by moabed            #+#    #+#             */
/*   Updated: 2026/01/12 17:00:27 by moabed           ###   ########.fr       */
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
# include <math.h>
# define WIDTH 1080
# define HEIGHT 1080

# define RED	0xFF0000   // Red is max, Green is 0, Blue is 0
# define GREEN	0x00FF00 // Red is 0, Green is max, Blue is 0
# define BLUE	0x0000FF  // Red is 0, Green is 0, Blue is max
# define BLACK	0x000000   // All lights off
# define WHITE	0xFFFFFF   // All lights on (max intensity)

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
	double	escape_value;// الوتر حسب نظرية فيثاغورس 
	double	real_shift;
	double	i_shift;
	double zoom;
	t_image	img;
	
}			t_fractal;

// mandlebrot
void	mandlebrot(t_complex *z, t_complex *c);
// initialization function
void	fractal_init(t_fractal *fractal);
void	data_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);
// rendering and pixels operations
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	fractal_render(t_fractal *fractal);
// mlx_ops

// keys ops
int		image_handler(t_fractal *fractal);
int		key_handler(int key, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
void	mlx(t_fractal *fractal);

void		malloc_fail(void);

#endif