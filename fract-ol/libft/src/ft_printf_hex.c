/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:16 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/18 05:54:20 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hex(unsigned int num, char type)
{
	size_t	count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (type == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_printf_hex(num / 16, type);
	return (count += ft_printf_char(hex_digits[num % 16]));
}
