/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:26:03 by darkwater         #+#    #+#             */
/*   Updated: 2024/05/01 17:33:04 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
//# include "../mlx_swift/mlx.h"	- Swift Version
# include "../mlx_opengl/mlx.h"		// openGL Version
# include "../libft/includes/libft.h"

//Screen Size Variables

# ifndef SIZE_X
#  define SIZE_X 800
# endif

# ifndef SIZE_Y
#  define SIZE_Y 800
# endif

//Event Codes

# define ESC 53
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*window_ptr;
	void			*img_ptr;
	char			*address;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			scale;
	double			x;
	double			y;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	double			temp;
	char			frac_type;
}				t_vars;

//miniLibX Functions

int				add_shade(double distance, int colour);
int				clean_destroy(t_vars *vars);
int				mouse_handles(int button, int x, int y, t_vars *vars);
int				trgb_convert(int t, int r, int g, int b);
int				win_close(int keycode, t_vars *vars);

void			my_mlx_pixel_put(t_vars *vars, int x, int y, int colour);

//fract-ol Functions

int				print_julia(t_vars *vars, int step);

double			ft_atod_fractol(char *str);

void			draw_fractal(t_vars *vars);
void			ft_julia(t_vars *vars);
void			ft_mandelbrot(t_vars *vars);
void			list_params(void);
void			print_mandelbrot(t_vars *vars, int step);

#endif
