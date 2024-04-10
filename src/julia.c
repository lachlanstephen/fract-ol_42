/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:29 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/10 23:05:46 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
The Filled Julia Set equation is fc(Z) = Z^2 + C where C IS FIXED.

Z is the starting point of the function in the complex plane. 
Z = a + bi
E.g. Z = .0025 + .06i

Definiton: Filled Julia Set is the set of complex numbers Z,
so that under iteration by the function applied with the fixed value of C,
the values don't get arbitrarily large.

Filled Julia Set is essentially a subset of the Mandelbrot Set,
as in all Filled Julia Sets are contained within the Mandelbrot Set.
*/

void	ft_julia(t_vars *vars)
{
	int	step;

	while (vars->x < SIZE_X)
	{
		vars->y = 0;
		while (vars->y < SIZE_Y)
		{
			vars->zx = ((4 * vars->x) - (2 * SIZE_X)) / SIZE_X;
			vars->zy = ((-4 * vars->y) + (2 * SIZE_Y)) / SIZE_Y;
			step = print_julia(vars, 0);
			if (step >= 100)
				my_mlx_pixel_put(vars, vars->x, vars->y, 0x00000000);
			else
				my_mlx_pixel_put(vars, vars->x, vars->y, trgb_convert(0, 0 + (255 * step / 50),0 + (255 * step / 50),0 + (255 * step / 50)));
			vars->y++;
		}
		vars->x++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr,
		vars->img_ptr, 0, 0);
}

/* TO ADD IF YOU"D LIKE SOME PRETTY COLOUR */
//				my_mlx_pixel_put(vars, vars->x, vars->y,
//					trgb_convert(0,
//						(100 + step * 10) % 255, (0 + step * 8) % 255,
//						(96 + step * 9) % 255));
