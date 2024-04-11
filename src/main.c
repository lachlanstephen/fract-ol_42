/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:25:01 by darkwater         #+#    #+#             */
/*   Updated: 2024/04/11 13:16:46 by lstephen         ###   ########.fr       */
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

static void	vars_initialise(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
	{
		perror("Error: ");
		exit(1);
	}
	vars->window_ptr = mlx_new_window(vars->mlx_ptr,
			SIZE_X, SIZE_Y, "fract-ol");
	if (vars->window_ptr == NULL)
	{
		perror("Error: ");
		free(vars->mlx_ptr);
		exit(1);
	}
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, SIZE_X, SIZE_Y);
	vars->address = mlx_get_data_addr(vars->img_ptr, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->scale = 1;
	vars->cx = 0;
	vars->cy = 0;
	vars->temp = 0;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	param_checker(argv, argc);
	vars_initialise(&vars);
	if (argv[1][0] == 'm')
		vars.frac_type = 'm';
	else if (argv[1][0] == 'j')
	{
		vars.frac_type = 'j';
		if (argc == 4 && argc--)
			vars.cy = ft_atod_fractol(argv[3]);
		if (argc == 3)
			vars.cx = ft_atod_fractol(argv[2]);
	}
	draw_fractal(&vars);
	mlx_key_hook(vars.window_ptr, win_close, &vars);
	mlx_mouse_hook(vars.window_ptr, mouse_handles, &vars);
	mlx_hook(vars.window_ptr, 17, 0, clean_destroy, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
