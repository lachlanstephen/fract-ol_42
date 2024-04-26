/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:34:43 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/18 05:55:17 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_unsigned(unsigned int num)
{
	size_t	count;

	count = 0;
	if (num >= 10)
		count += ft_printf_unsigned(num / 10);
	return (count += ft_printf_char(num % 10 + '0'));
}
