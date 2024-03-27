/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:20:08 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/18 16:28:11 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	new_str = malloc(sizeof(char) * i + 1);
	if (new_str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != 0)
	{
		new_str[i] = (f(i, str[i]));
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
