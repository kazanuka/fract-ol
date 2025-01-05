/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:01:36 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 16:02:09 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->window);
	free(fractol->mlx);
	free(fractol);
	exit(1);
	return (0);
}

int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == ESC)
		exit_fractal(fractol);
	else if (key_code == LEFT)
		fractol->off_x -= 42 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->off_x += 42 / fractol->zoom;
	else if (key_code == UP)
		fractol->off_y -= 42 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->off_y += 42 / fractol->zoom;
	else if (key_code == R)
		init_fractol(fractol);
	else if (key_code == C)
		fractol->color += (255 * 255 * 255) / 100;
	/* else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code); */
	draw(fractol, "mbrot");
	return (0);
}