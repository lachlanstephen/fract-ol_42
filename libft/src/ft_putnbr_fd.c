/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:48:29 by lstephen          #+#    #+#             */
/*   Updated: 2023/08/19 19:07:49 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prn_num(long num, int fd)
{
	char	temp;

	temp = '\0';
	if (num != 0)
	{
		prn_num(num / 10, fd);
	}
	if (num != 0)
	{
		temp = num % 10 + '0';
		ft_putchar_fd(temp, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num == 0)
	{
		write(fd, "0", 1);
	}
	else if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num != 0)
	{
		prn_num(num, fd);
	}
}
