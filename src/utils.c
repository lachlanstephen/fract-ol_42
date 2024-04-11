/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:26:07 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/11 13:14:03 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	ft_get_decimal(char *str, int i)
{
	double	frac;
	int		sig;

	frac = 0;
	sig = 0;
	while (str[i + ++sig] != 0)
	{
		if (str[i + sig] > '9' || str[i + sig] < '0')
			list_params();
		frac *= 10;
		frac += str[i + sig] - '0';
	}
	while (--sig > 0)
		frac /= 10;
	return (frac);
}

double	ft_atod_fractol(char *str)
{
	double	res;
	int		i;
	bool	neg;
	double	frac;

	res = 0;
	i = -1;
	frac = 0;
	neg = false;
	if (str[0] == '-' && i++)
		neg = true;
	while (str[++i] != 0 && str[i] != '.')
	{
		if (str[i] > '9' || str[i] < '0')
			list_params();
		res *= 10;
		res += str[i] - '0';
	}
	if (str[i] == '.')
		frac = ft_get_decimal(str, i);
	res += frac;
	if (neg)
		res *= -1;
	return (res);
}
