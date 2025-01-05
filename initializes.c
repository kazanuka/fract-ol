/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:15 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 15:11:30 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractol(t_fractol *fractal) // Struct'da belirttiğim fractolün default değerlerini ayarlıyorum.
{
    fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->off_x = -1.21;
	fractal->off_y = -1.21;
	fractal->max_iterations = 42;
    fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}