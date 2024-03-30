/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:55:24 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/31 04:59:15 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->address + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	not_main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx_ptr = mlx_init();
	vars.window_ptr = mlx_new_window(vars.mlx_ptr, 1080, 1080, "Test Images");
	img.img_ptr = mlx_new_image(vars.mlx_ptr, 1080, 1080);
	img.address = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	//printing_shapes(&img, mlx_ptr, window_ptr);
	//changing_colours(&img, mlx_ptr, window_ptr);
	//adding_texture(&img, mlx_ptr, window_ptr);
	//mlx_hook(vars.window_ptr, 2, 0, win_close, &vars);
	//mlx_hook(vars.window_ptr, 25, 1L<<18, win_resize, &vars);
//	mlx_hook(vars.window_ptr, 6, 0, print_coords, &vars);
//	mlx_hook(vars.window_ptr, 7, 0, mouse_enter_noti, &vars);
//	mlx_key_hook(vars.window_ptr, key_hook, &vars);
//	mlx_mouse_hook(vars.window_ptr, mouse_hook, &vars);
//	mlx_loop(vars.mlx_ptr);
	return (0);
}
