/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:00:58 by darkwater         #+#    #+#             */
/*   Updated: 2023/08/18 15:51:15 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_length(int n)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*char_convert(char *num, size_t len, size_t limit, int n)
{
	size_t	pos;
	long	value;

	pos = 0;
	value = (long)n;
	if (value < 0)
	{
		num[0] = '-';
		limit++;
		value *= -1;
	}
	while (pos < len && len - pos - 1 >= limit)
	{
		num[len - pos - 1] = (value % 10) + '0';
		value /= 10;
		pos++;
	}
	num[len] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	len;
	size_t	limit;

	len = 0;
	limit = 0;
	if (n <= 0)
		len++;
	len += num_length(n);
	num = malloc(sizeof(char) * len + 1);
	if (num == NULL)
		return (NULL);
	return (char_convert(num, len, limit, n));
}
