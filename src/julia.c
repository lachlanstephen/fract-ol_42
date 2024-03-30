/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:29 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/31 05:31:40 by lstephen         ###   ########.fr       */
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

void	ft_julia(double complex c, t_data *img, t_vars *vars)
{
	double			x;
	double			y;
	double complex	z;

	x = -2;
	while (x < 2)
	{
		x += .001;
		y = -2;
		while (y < 2)
		{
			y += .001;
			z = CMPLX(x, y);
			if (print_julia(z, c, 0, img))
				my_mlx_pixel_put(img, (SIZE_X / 2 + SIZE_X / 4 * creal(z)),
					(SIZE_Y / 2 - SIZE_Y / 4 * cimag(z)), 0x000000);
			else
				my_mlx_pixel_put(img, (SIZE_X / 2 + SIZE_X / 4 * creal(z)),
					(SIZE_Y / 2 - SIZE_Y / 4 * cimag(z)), 0xFFFFFF);
		}
	}
	ft_printf("This is the Julia Set!\n");
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr,
		img->img_ptr, 0, 0);
}
