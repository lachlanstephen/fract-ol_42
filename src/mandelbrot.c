/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:22:08 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/30 00:36:24 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * The mandelbrot set equation is that of Z(n+1) = Z(n)^2 + C
 * Iterate from 0 and move your way up through the results, make sure it never surpasses 2
 */

void	print_res(float n, float c, int step)
{
	float	res;

	res = 0;
	if (step >= 100)
		return ;
	if (n > 2 || n < -2)
		return ;
	printf("%f\n", res = pow(n, 2) + c);
	print_res(res, c, ++step);
}

void	ft_mandelbrot(float constant)
{
	print_res(0, constant, 0);
	ft_printf("This is the Mandelbrot set!\n");
}
