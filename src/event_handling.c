/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:43 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/11 02:25:00 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		clean_destroy(vars);
	return (0);
}

int	mouse_handles(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP)
		vars->scale += .1;
	else if (button == SCROLL_DOWN)
	{
		if (vars->scale > 1)
			vars->scale -= .1;
	}
	draw_fractal(vars);
	(void)x, (void)y;
	return (0);
}
