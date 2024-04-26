/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:41:19 by darkwater         #+#    #+#             */
/*   Updated: 2023/08/14 21:15:14 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	max;

	i = 0;
	max = ft_strlen(str);
	if (start >= max || max == 0)
		sub = malloc(sizeof(char) * 1);
	else if (max - start < len)
		sub = malloc(sizeof(char) * (max - start) + 1);
	else
		sub = malloc(sizeof(char) * len + 1);
	if (sub == NULL)
		return (NULL);
	while (start < max && str[start + i] != 0 && i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	if (start >= max || str[start + i] == 0 || i == len)
		sub[i] = '\0';
	return (sub);
}
