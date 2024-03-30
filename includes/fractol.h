/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:26:03 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/31 04:27:21 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <complex.h>
# include <math.h>
# include "../mlx_swift/mlx.h"
# include "../libft/includes/libft.h"

# ifndef SIZE_X
#  define SIZE_X 1080
# endif

# ifndef SIZE_Y
#  define SIZE_Y 1080
# endif

typedef struct s_data
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*window_ptr;
}				t_vars;

//miniLibX Functions

int				trgb_convert(int t, int r, int g, int b);
int				add_shade(double distance, int colour);

void			my_mlx_pixel_put(t_data *data, int x, int y, int colour);


//fract-ol Functions

bool			print_julia(complex double n, complex double c, int step, t_data *img);

float			ft_atof_fractol(char *str);

void			ft_julia(double real, double imag, t_data *img, t_vars *vars);
void			ft_mandelbrot(t_data *img, t_vars *vars);
void			list_params(void);
void			print_mandelbrot(complex double n, complex double c, double step, t_data *img);

#endif
