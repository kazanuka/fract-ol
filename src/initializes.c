/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:15 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:46 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->jul_x = -0.7;
	fractol->jul_y = 0.2715;
	fractol->color = 0x1E90FF;
	fractol->zoom = 400;
	fractol->off_x = -2;
	fractol->off_y = -0.3;
	fractol->max_iterations = 50;
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "Fractol");
	fractol->img = mlx_new_image(fractol->mlx, SIZE, SIZE);
	if (!(fractol->mlx) || !(fractol->img) || !(fractol->window))
		exit_fractal(fractol);
	fractol->img_ptr = mlx_get_data_addr(fractol->img,
			&fractol->bits_per_pixel,
			&fractol->size_line,
			&fractol->end);
}
