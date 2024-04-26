/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 05:26:37 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/31 05:27:08 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	trgb_convert(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	t_input(int colour)
{
	return ((colour >> 24) & 0xFF);
}

int	r_input(int colour)
{
	return ((colour >> 16) & 0xFF);
}

int	g_input(int colour)
{
	return ((colour >> 8) & 0xFF);
}

int	b_input(int colour)
{
	return (colour & 0xFF);
}

/*
int	add_shade(double distance, int colour)
{
	int	trgb[4];

	trgb[0] = 255 * distance;
	trgb[1] = r_input(colour);
	trgb[2] = g_input(colour);
	trgb[3] = b_input(colour);
	return (trgb_convert(trgb[0], trgb[1], trgb[2], trgb[3]));
}
*/
