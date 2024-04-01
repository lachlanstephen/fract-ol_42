/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:25:01 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/02 06:26:00 by lstephen         ###   ########.fr       */
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
	if ((argc < 2 || argc > 4)
		|| (argv[1][0] != 'm' && argv[1][0] != 'j')
		|| (argv[1][0] == 'm' && (argv[1][1] != 0 || argc > 2))
		|| (argv[1][0] == 'j' && (argv[1][1] != 0 || argc > 4)))
		list_params();
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	param_checker(argv, argc);
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (1);
	vars.window_ptr = mlx_new_window(vars.mlx_ptr, SIZE_X, SIZE_Y, "fract-ol");
	if (vars.window_ptr == NULL)
		return (free(vars.mlx_ptr), 1);
	vars.img_ptr = mlx_new_image(vars.mlx_ptr, SIZE_X, SIZE_Y);
	vars.address = mlx_get_data_addr(vars.img_ptr, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	if (argv[1][0] == 'm')
		ft_mandelbrot(&vars);
	else if (argv[1][0] == 'j')
	{
		if (argc == 3)
			ft_julia(CMPLX(ft_atof_fractol(argv[2]), 0), &vars, 0);
		else if (argc == 4)
			ft_julia(CMPLX(ft_atof_fractol(argv[2]), ft_atof_fractol(argv[3]))
				, &vars, 0);
		else
			ft_julia(0, &vars, 0);
	}
	mlx_key_hook(vars.window_ptr, win_close, &vars);
	mlx_hook(vars.window_ptr, 17, 0, clean_destroy, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
