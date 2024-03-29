/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:29 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/30 06:39:13 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
The Filled Julia Set equation is fc(Z) = Z^2 + C where C IS FIXED.

Definiton: Filled Julia Set is the set of complex numbers Z, so that under iteration by the function applied with the fixed value of C, the values don't get arbitrarily large
Filled Julia Set is essentially a subset of the Mandelbrot Set, as in all Filled Julia Sets are contained within the Mandelbrot Set.
*/

void	ft_julia(float constant)
{
	double	x;
	double	y;
	double complex	z;

	x = -2;
	while (x <= 2)
	{
		y = -2;
		while (y <= 2)
		{
			z = x + y * I;
			print_res(z, constant, 0);
			y += .001;
		}
		x += .001;
	}
	ft_printf("This is the Julia Set!\n");
}
