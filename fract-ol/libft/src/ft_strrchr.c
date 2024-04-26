/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 05:07:50 by darkwater         #+#    #+#             */
/*   Updated: 2023/08/11 22:09:08 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	pos;

	pos = ft_strlen(str);
	if ((char)c == '\0')
	{
		return ((char *)&str[pos]);
	}
	pos--;
	while (pos >= 0)
	{
		if (str[pos] == (char)c)
		{
			return ((char *)&str[pos]);
		}
		pos--;
	}
	return (NULL);
}
