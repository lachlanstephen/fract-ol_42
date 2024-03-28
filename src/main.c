/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:25:01 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/28 17:41:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	list_params(void)
{
	ft_printf("Parameters: './fractol [Set] [Option]'\n\n~ ~ Sets ~ ~\n\n'm' - Mandelbrot Set\n\n'j' - Julia Set\n\nExample: './fractol j .0065'\n");
	exit(1);
}

static void	param_checker(char **argv, int argc)
{
	int	i;

	i = 1;
	(void)argc;
	if (argv[i][0] != 'm' && argv[i][0] != 'j')
		list_params();
	/*while (++i < argc)
	{
		if (argv[i]
*/
}

int	main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
		list_params();
	param_checker(argv, argc);
	if (argv[1][0] == 'm')
		ft_mandelbrot();
	else if (argv[1][0] == 'j' && argc == 3)
		ft_julia(ft_atof_fractol(argv[2]));
	return (0);
}
