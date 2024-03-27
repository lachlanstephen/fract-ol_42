/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:23:21 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/11 20:09:34 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	while (src[i] != 0 && i < destsize - 1 && destsize != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (destsize != 0)
	{
		dest[i] = '\0';
	}
	return (len);
}
