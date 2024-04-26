/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:24:41 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/14 21:37:53 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_whitespace(const char *str)
{
	size_t	i;
	char	*skip;

	i = 0;
	skip = (char *)str;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	return (&skip[i]);
}

static bool	is_negative(char c)
{
	if (c == '-')
	{
		return (true);
	}
	return (false);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long int	res;
	int			temp;

	i = 0;
	res = 0;
	str = skip_whitespace(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0)
	{
		temp = str[i] - '0';
		if (temp < 0 || temp > 9)
		{
			break ;
		}
		res *= 10;
		res += temp;
		i++;
	}
	if (is_negative(str[0]))
	{
		res *= -1;
	}
	return ((int)res);
}
