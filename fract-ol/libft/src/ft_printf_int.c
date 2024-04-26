/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:13:21 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/18 05:54:37 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_int(int num)
{
	size_t	count;
	char	*str;

	str = ft_itoa(num);
	count = ft_printf_str(str);
	free(str);
	return (count);
}
