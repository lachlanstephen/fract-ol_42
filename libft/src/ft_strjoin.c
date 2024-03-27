/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:29:09 by darkwater         #+#    #+#             */
/*   Updated: 2023/08/14 21:17:34 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t	len;
	char	*res;
	size_t	i;

	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	len = 0;
	while (str1[i] != 0)
	{
		res[len] = str1[i];
		i++;
		len++;
	}
	i = 0;
	while (str2[i] != 0)
	{
		res[len] = str2[i];
		i++;
		len++;
	}
	res[len] = '\0';
	return (res);
}
