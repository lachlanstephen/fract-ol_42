/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 05:07:44 by darkwater         #+#    #+#             */
/*   Updated: 2023/08/14 05:20:33 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t amnt, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc(amnt * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	while (i < amnt * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
