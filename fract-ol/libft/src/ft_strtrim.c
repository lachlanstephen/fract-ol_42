/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:53:43 by darkwater         #+#    #+#             */
/*   Updated: 2023/08/14 22:34:49 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(const char *str, const char *set)
{
	size_t	start;
	size_t	j;

	start = 0;
	j = 0;
	while (set[j] != 0 && str[start] != 0)
	{
		if (set[j] == str[start])
		{
			start++;
			j = 0;
		}
		else
		{
			j++;
		}
	}
	return (start);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	start;
	size_t	len;
	size_t	i;
	char	*res;

	i = 0;
	len = ft_strlen(str);
	if (len != 0)
		len--;
	start = get_start(str, set);
	while (set[i] != 0 && len > 0)
	{
		if (set[i] == str[len])
		{
			len--;
			i = 0;
		}
		else
		{
			i++;
		}
	}
	res = ft_substr(str, start, len - start + 1);
	return (res);
}
