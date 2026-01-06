/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:07:52 by moabed            #+#    #+#             */
/*   Updated: 2026/01/05 21:47:09 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <sys/time.h>
# define WIDTH 1920
# define HEIGHT 1080
// Primary Colors
# define RED 0xFF0000   // Red is max, Green is 0, Blue is 0
# define GREEN 0x00FF00 // Red is 0, Green is max, Blue is 0
# define BLUE 0x0000FF  // Red is 0, Green is 0, Blue is max

// Secondary/Mixed Colors
# define BLACK 0x000000   // All lights off
# define WHITE 0xFFFFFF   // All lights on (max intensity)
# define YELLOW 0xFFFF00  // Red + Green
# define CYAN 0x00FFFF    // Green + Blue
# define MAGENTA 0xFF00FF // Red + Blue

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
	double	escape_value;
	int		init_iteration;

}			t_fractal;

// mandlebrot
void		mandlebrot(t_complex *z, t_complex *c);
// initialization function
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
// rendering and pixels operations
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
void		fractal_render(t_fractal *fractal);

void		malloc_fail(void);
#endif