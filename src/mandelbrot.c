/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:22:08 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/30 05:49:12 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* 
The Mandelbrot set equation is that of Z(n+1) = Z(n)^2 + C, for all values of C within radius 2

Iterate from 0 and move your way up through the results, make sure it never surpasses 2

To create the Mandelbrot set, must use different values of C contained within radius 2 from origin.

Definition: Mandelbrot set is the set of complex numbers c, for which the distance from the origin of the complex plane is bounded
 */

void	ft_mandelbrot(void)
{
	double	x;
	double	y;
	complex	c;

	x = -5.000;
	while (++x < 5)
	{
		y = -5.000;
		while (++y < 5)
		{
			c = x + y * I;
			print_res(0, c, 0);
		}
	}
	ft_printf("This is the Mandelbrot set!\n");
}
