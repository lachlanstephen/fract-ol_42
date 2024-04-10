/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:46:24 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/11 02:40:21 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_julia(t_vars *vars, int step)
{
	if (step >= 100 || (vars->zx * vars->zx) >= 4 || (vars->zy * vars->zy) >= 4)
		return (step);
	vars->temp = vars->zx * vars->zx - vars->zy * vars->zy + vars->cx;
	vars->zy = 2 * vars->zx * vars->zy + vars->cy;
	vars->zx = vars->temp;
	return (print_julia(vars, ++step));
}

void	print_mandelbrot(t_vars *vars, int step)
{
	if (step >= 100)
	{
		my_mlx_pixel_put(vars, vars->x, vars->y, 0x00000000);
		return ;
	}
	if ((vars->zx * vars->zx) >= 4 || (vars->zy * vars->zy) >= 4)
	{
		my_mlx_pixel_put(vars, vars->x, vars->y, trgb_convert(0,
				0 + (255 * step / 50),
				0 + (255 * step / 50),
				0 + (255 * step / 50)));
		return ;
	}
	vars->temp = vars->zx * vars->zx - vars->zy * vars->zy + vars->cx;
	vars->zy = 2 * vars->zx * vars->zy + vars->cy;
	vars->zx = vars->temp;
	print_mandelbrot(vars, ++step);
}

/* TO ADD IF YOU"D LIKE SOME PRETTY COLOUR */
//		my_mlx_pixel_put(vars, vars->x, vars->y, trgb_convert(0,
//				(100 + step * 10) % 255,
//				(0 + step * 8) % 255,
//				(96 + step * 9) % 255));
