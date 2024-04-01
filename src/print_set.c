/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:46:24 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/02 09:22:53 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_julia(double complex n, double complex c, int step, t_vars *vars)
{
	if (step >= 100 || cabs(n) >= 2)
		return (step);
	n = n * n + c;
	return (print_julia(n, c, ++step, vars));
}

void	print_mandelbrot(double complex n, double complex c,
	int step, t_vars *vars)
{
	double	coord[2];

	coord[0] = SIZE_X / 2 + (SIZE_X / 4 * creal(c) * vars->scale);
	coord[1] = SIZE_Y / 2 - (SIZE_Y / 4 * cimag(c) * vars->scale);
	if (step >= 100)
	{
		if (coord[0] >= 0 && coord[1] >= 0 && coord[0] < SIZE_X && coord[1] < SIZE_Y)
			my_mlx_pixel_put(vars, coord[0], coord[1], 0x00000000);
		return ;
	}
	if (cabs(n) >= 2)
	{
		if (coord[0] >= 0 && coord[1] >= 0 && coord[0] < SIZE_X && coord[1] < SIZE_Y)
			my_mlx_pixel_put(vars, coord[0], coord[1], trgb_convert(0,
					0 + (255 * step / 50), 0 + (255 * step / 50),
					0 + (255 * step / 50)));
		return ;
	}
	n = n * n + c;
	print_mandelbrot(n, c, ++step, vars);
}

/* TO ADD IF YOU"D LIKE SOME PRETTY COLOUR */
//		my_mlx_pixel_put(vars, (SIZE_X / 2 + SIZE_X / 4 * creal(c)),
//			(SIZE_Y / 2 - SIZE_Y / 4 * cimag(c)), trgb_convert(0,
//				(100 + step * 10) % 255, (0 + step * 8) % 255,
//				(96 + step * 9) % 255));
