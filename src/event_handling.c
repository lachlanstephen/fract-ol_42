/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:43 by lstephen          #+#    #+#             */
/*   Updated: 2024/04/02 06:42:21 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	win_close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		clean_destroy(vars);
	return (0);
}

//int	on_destroy(
