/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:03:18 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/13 21:23:40 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	pos;
	size_t	sub_len;
	char	*mainstr;

	pos = 0;
	sub_len = ft_strlen(str2);
	mainstr = (char *)str1;
	if (sub_len == 0)
	{
		return (mainstr);
	}
	if (ft_strlen(str1) == 0)
	{
		return (NULL);
	}
	while ((pos + sub_len) <= n)
	{
		if (ft_strncmp(&mainstr[pos], str2, sub_len) == 0)
		{
			return (&mainstr[pos]);
		}
		pos++;
	}
	return (NULL);
}
