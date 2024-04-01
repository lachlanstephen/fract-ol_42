/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:26:03 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/02 06:30:32 by lstephen         ###   ########.fr       */
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
//# include <X11/X.h>
# include "../libft/includes/libft.h"

# ifndef SIZE_X
#  define SIZE_X 1080
# endif

# ifndef SIZE_Y
#  define SIZE_Y 1080
# endif

typedef struct s_vars
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*window_ptr;
}				t_vars;

//miniLibX Functions

int				trgb_convert(int t, int r, int g, int b);
int				add_shade(double distance, int colour);
int				win_close(int keycode, t_vars *vars);
int				clean_destroy(t_vars *vars);

void			my_mlx_pixel_put(t_vars *vars, int x, int y, int colour);


//fract-ol Functions

int				print_julia(complex double n, complex double c, int step, t_vars *vars);

float			ft_atof_fractol(char *str);

void			ft_julia(double complex c, t_vars *vars, int step);
void			ft_mandelbrot(t_vars *vars);
void			list_params(void);
void			print_mandelbrot(complex double n, complex double c, int step, t_vars *vars);

#endif
