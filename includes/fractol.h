/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkwater <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:26:03 by darkwater         #+#    #+#             */
/*   Updated: 2024/03/28 17:37:30 by darkwater        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <complex.h>
# include "../libft/includes/libft.h"

float			ft_atof_fractol(char *str);

void			ft_julia(float constraint);
void			ft_mandelbrot(void);

#endif
