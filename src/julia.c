/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:29 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/02 05:58:36 by lstephen         ###   ########.fr       */
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

void	ft_julia(double complex c, t_vars *vars, int step)
{
	double			coord[2];
	double complex	z;

	coord[0] = -1.999;
	while (coord[0] < 2)
	{
		coord[1] = -1.999;
		while (coord[1] < 2)
		{
			z = CMPLX(coord[0], coord[1]);
			step = print_julia(z, c, 0, vars);
			if (step >= 100)
				my_mlx_pixel_put(vars, (SIZE_X / 2 - SIZE_X / 4 * creal(z)),
					(SIZE_Y / 2 - SIZE_Y / 4 * cimag(z)), 0x00000000);
			else
				my_mlx_pixel_put(vars, (SIZE_X / 2 - SIZE_X / 4 * creal(z)),
					(SIZE_Y / 2 - SIZE_Y / 4 * cimag(z)), trgb_convert(0,
						0 + (255 * step / 50), 0 + (255 * step / 50),
						0 + (255 * step / 50)));
			coord[1] += .001;
		}
		coord[0] += .001;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr,
		vars->img_ptr, 0, 0);
}

/* TO ADD IF YOU"D LIKE SOME PRETTY COLOUR */
//				my_mlx_pixel_put(vars, (SIZE_X / 2 - SIZE_X / 4 * creal(z)),
//					(SIZE_Y / 2 - SIZE_Y / 4 * cimag(z)), trgb_convert(0,
//						(100 + step * 10) % 255, (0 + step * 8) % 255,
//						(96 + step * 9) % 255));
