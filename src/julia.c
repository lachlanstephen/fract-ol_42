/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:29 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/31 01:35:27 by lstephen         ###   ########.fr       */
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

void	ft_julia(double real, double imag, t_data *img, t_vars *vars)
{
	double	x;
	double	y;
	double complex	z;
	double complex	c;

	c = CMPLX(real, imag);;
	x = -2;
	while (x < 2)
	{
		x += .001;
		y = -2;
		while (y < 2)
		{
			y += .001;
			z = CMPLX(x, y);
			print_julia(z, c, 0, img);
		}
	}
	ft_printf("This is the Julia Set!\n");
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr, img->img_ptr, 0, 0);
}
