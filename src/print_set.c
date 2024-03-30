/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:46:24 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/31 04:28:35 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	print_julia(double complex n, double complex c, int step, t_data *img)
{
	if (step >= 100)
		return true;
	if (cabs(n) >= 2)
		return false;
	n = n * n + c;
	return (print_julia(n, c, ++step, img));
}

void	print_mandelbrot(double complex n, double complex c, double step, t_data *img)
{
	if (step >= 100)
	{
		my_mlx_pixel_put(img, (SIZE_X / 2 + SIZE_X / 4 * creal(c)), (SIZE_Y / 2 - SIZE_Y / 4 * cimag(c)), 0x000000);
		return ;
	}
	if (cabs(n) >= 2)
	{
		my_mlx_pixel_put(img, (SIZE_X / 2 + SIZE_X / 4 * creal(c)), (SIZE_Y / 2 - SIZE_Y / 4 * cimag(c)), 0xFFFFFF);
		return ;
	}
	n = n * n + c;
	print_mandelbrot(n, c, ++step, img);
}
