/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:26:07 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/28 17:50:31 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

float	ft_atof_fractol(char *str)
{
	float	res;
	int		i;
	bool	neg;
	float	frac;
	int		sig;

	res = 0;
	i = -1;
	frac = 0;
	sig = 0;
	if (str[0] == '-' && i++)
		neg = true;
	while (str[++i] != 0 && str[i] != '.')
	{
		res *= 10;
		res += str[i] - '0';
	}
	if (str[i] == '.')
	{
		while (str[i + ++sig] != 0)
		{
			frac *= 10;
			frac += str[i + sig] - '0';
		}
		while (--sig > 0)
			frac /= 10;
	}
	res += frac;
	if (neg)
		return (res * -1);
	return (res);
}
