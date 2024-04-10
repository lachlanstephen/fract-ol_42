/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:42:13 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/10 19:33:44 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_fractal(t_vars *vars)
{
	if (vars->frac_type == 'm')
		ft_mandelbrot(vars);
	else if (vars->frac_type == 'j')
		ft_julia(vars);
}
