/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:22:08 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/02 09:30:18 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* 
The Mandelbrot set equation is that of Z(n+1) = Z(n)^2 + C,
for all values of C within radius 2

Iterate from 0 and move your way up through the results,
make sure it never surpasses 2

To create the Mandelbrot set, must use different values of C
contained within radius 2 from origin.

Definition: Mandelbrot set is the set of complex numbers c,
for which the distance from the origin of the complex plane is bounded
*/

void	ft_mandelbrot(t_vars *vars)
{
	double			x;
	double			y;
	double complex	c;

	x = -1.999;
	while (x < 2)
	{
		y = -1.999;
		while (y < 2)
		{
			c = CMPLX(x, y);
			print_mandelbrot(0, c, 0, vars);
			y += .001;
		}
		x += .001;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr,
		vars->img_ptr, 0, 0);
}
