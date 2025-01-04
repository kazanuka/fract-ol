/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:15 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/04 14:29:08 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_fractol(t_fractol *fractol)//Struct'da belirttiğim fractolün default değerlerini ayarlıyorum.
{
    fractol -> x = 0;
    fractol -> y = 0;
    fractol -> color = 0xFCBE11;
    fractol -> zoom = 0;
    fractol -> off_x = -1;
    fractol -> off_y = -1;
    fractol -> max_iterations = 32;
}

void    init_mlx(t_fractol *fractol)
{
    fractol -> mlx = mlx_init();
    fractol -> window = mlx_new_window(fractol->mlx,SIZE,SIZE, "Fractol");
    fractol -> img = mlx_new_image(fractol->mlx,SIZE,SIZE);
    fractol->pointer_to_image = mlx_get_data_addr(fractol->img,
			&fractol->bits_per_pixel,
			&fractol->size_line,
			&fractol->endian);
}