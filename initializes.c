/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:15 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 18:49:03 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractol(t_fractol *fractol)//Struct'da belirttiğim fractolün def
{
    fractol->x = 0;
	fractol->y = 0;
	fractol->jul_x = -0.7;
	fractol->jul_y = 0.2715;
	fractol->color = 0x123456;
	fractol->zoom = 300;
	fractol->off_x = -1.21;
	fractol->off_y = -1.21;
	fractol->max_iterations = 42;
    fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "Fract-ol");
	fractol->img = mlx_new_image(fractol->mlx, SIZE, SIZE);
	fractol->pointer_to_image = mlx_get_data_addr(fractol->img,
			&fractol->bits_per_pixel,
			&fractol->size_line,
			&fractol->endian);
}


