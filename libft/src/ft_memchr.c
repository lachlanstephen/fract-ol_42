/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:20:30 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/13 19:33:54 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cast;

	cast = (unsigned char *)str;
	while (n > 0)
	{
		if (*cast == (unsigned char)c)
		{
			return ((void *)cast);
		}
		cast++;
		n--;
	}
	return (NULL);
}
