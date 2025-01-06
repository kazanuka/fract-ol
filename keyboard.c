/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:01:36 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 19:04:35 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	zoom(t_fractol *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.5;
	if (zoom == 1)
	{
		fractal->off_x = (x / fractal->zoom + fractal->off_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->off_y = (y / fractal->zoom + fractal->off_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->off_x = (x / fractal->zoom + fractal->off_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->off_y = (y / fractal->zoom + fractal->off_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}


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
		fractol->off_x -= 50 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->off_x += 50 / fractol->zoom;
	else if (key_code == UP)
		fractol->off_y -= 50 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->off_y += 50 / fractol->zoom;
	draw(fractol, fractol->name);
	return (0);
}

int mouse_hook(int mouse, int x, int y, t_fractol *fractol)
{
	if (mouse == SCROLL_UP)
		zoom(fractol, x, y, 1);
	else if (mouse == SCROLL_DOWN)
		zoom(fractol, x, y, -1);
	draw(fractol, fractol->name);
	return (0);
}
