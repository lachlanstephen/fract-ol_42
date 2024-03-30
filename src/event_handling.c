/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:43 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/30 20:51:49 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx_ptr, vars->window_ptr);
	(void)vars;
	return (0);
}

int	win_resize(void)
{
	printf("Attempting to resize window!\n");
	return (0);
}

int	mouse_enter_noti(int x, int y, t_vars *vars)
{
	printf("The mouse entered at %d, %d\n", x, y);
	(void)vars;
	return (0);
}
