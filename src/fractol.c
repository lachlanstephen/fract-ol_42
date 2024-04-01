/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:42:13 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/02 08:56:06 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_vars *vars)
{
	double complex	c;

	c = CMPLX(vars->option1, vars->option2);
	if (vars->frac_type == 'm')
		ft_mandelbrot(vars);
	else if (vars->frac_type == 'j')
		ft_julia(c, vars, 0);
}
