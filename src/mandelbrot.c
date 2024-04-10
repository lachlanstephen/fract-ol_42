/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:22:08 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/10 23:04:18 by lstephen         ###   ########.fr       */
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
	while (vars->x < SIZE_X)
	{
		vars->cx = (((4 * vars->x) - (2 * SIZE_X)) / SIZE_X);
		vars->y = 0;
		while (vars->y < SIZE_Y)
		{
			vars->zx = 0;
			vars->zy = 0;
			vars->cy = (((-4 * vars->y) + (2 * SIZE_Y)) / SIZE_Y);
			print_mandelbrot(vars, 0);
			vars->y++;
		}
		vars->x++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr,
		vars->img_ptr, 0, 0);
}
