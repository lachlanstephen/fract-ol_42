/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 05:46:24 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/30 05:46:25 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_res(float n, float c, int step)
{
	if (step >= 100)
		return ;
	if (n >= 2 || n <= -2)
		return ;
	printf("%f Step: %d\n", n = pow(n, 2) + c, step);
	print_res(n, c, ++step);
}

