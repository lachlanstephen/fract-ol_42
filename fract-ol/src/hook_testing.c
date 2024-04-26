/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstephen <lstephen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:04:46 by lstephen          #+#    #+#             */
/*   Updated: 2024/03/30 20:51:57 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("Keycode: %d\n", keycode);
	(void)vars;
	return (0);
}

int	mouse_hook(int mousecode, t_vars *vars)
{
	printf("This is my MOUSE HOOK!\n");
	(void)mousecode;
	(void)vars;
	return (0);
}

int	print_coords(int x, int y, t_vars *vars)
{
	printf("%d, %d\n", x, y);
	(void)vars;
	return (0);
}
