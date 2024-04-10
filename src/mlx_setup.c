/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:55:24 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/10 19:49:16 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int colour)
{
	char	*dst;

	dst = vars->address + (y * vars->line_length
			+ x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	clean_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->window_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	(void)vars;
	exit(0);
	return (0);
}
