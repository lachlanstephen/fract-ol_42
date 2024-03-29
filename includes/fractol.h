/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:26:03 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/30 00:34:47 by lstephen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <complex.h>
# include <math.h>
# include "../libft/includes/libft.h"

float			ft_atof_fractol(char *str);

void			ft_julia(float constant);
void			ft_mandelbrot(float constant);

#endif
