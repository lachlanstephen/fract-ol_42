/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:53:33 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/11 21:07:36 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len;

	i = ft_strlen(dest);
	len = i + ft_strlen(src);
	if (i >= destsize)
	{
		len = ft_strlen(src) + destsize;
	}
	else
	{
		ft_strlcpy(&dest[i], src, destsize - i);
	}
	return (len);
}
