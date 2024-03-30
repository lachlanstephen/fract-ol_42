/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:25:01 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/31 05:31:29 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	list_params(void)
{
	ft_printf("\nParameters: './fractol [Set] [Option1] [Option2]'\n\n\
~ ~ Sets ~ ~\n\n\t'm' - Mandelbrot Set\n\n\t\tNOTE: Mandelbrot Set does not accept options\n\n\
\t'j' - Julia Set\n\n\t\tNOTE: If no options passed, defaults to '0' '0'\n\n\
~ ~ Options ~ ~\n\nOptions ONLY accepts floats. Option 1 and Option 2 combine to form a complex number.\n\n\
\t[Option1] - Real Part\n\n\t[Option2] - Imaginary Part\n\n\
Example: './fractol j .0065 0.2'\n\n");
	exit(1);
}

static void	param_checker(char **argv, int argc)
{
	if ((argv[1][0] != 'm' && argv[1][0] != 'j')
		|| (argv[1][0] == 'm' && (argv[1][1] != 0 || argc > 2))
		|| (argv[1][0] == 'j' && (argv[1][1] != 0 || argc > 4)))
		list_params();
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_data	img;

	vars.mlx_ptr = mlx_init();
	vars.window_ptr = mlx_new_window(vars.mlx_ptr, SIZE_X, SIZE_Y, "fract-ol");
	img.img_ptr = mlx_new_image(vars.mlx_ptr, SIZE_X, SIZE_Y);
	img.address = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (argc < 2 || argc > 4)
		list_params();
	param_checker(argv, argc);
	if (argv[1][0] == 'm')
		ft_mandelbrot(&img, &vars);
	else if (argv[1][0] == 'j')
	{
		if (argc == 3)
			ft_julia(CMPLX(ft_atof_fractol(argv[2]), 0), &img, &vars);
		else if (argc == 4)
			ft_julia(CMPLX(ft_atof_fractol(argv[2]), ft_atof_fractol(argv[3])),
				&img, &vars);
		else
			ft_julia(0, &img, &vars);
	}
	mlx_loop(vars.mlx_ptr);
	return (0);
}
