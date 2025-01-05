/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:27:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 15:09:01 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mbrot(t_fractol *fractal)
{
    int		i;
	double	x_temp;

	fractal->name = "mbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->off_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->off_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		paint(fractal->x,fractal->y,fractal,0x000000);
	else
		paint(fractal->x,fractal->y,fractal,fractal->color *i);
}

void	paint(int x, int y, t_fractol *fractol, int color)//	bu fonksiyona iyi bak
{
	int	*buffer;

    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        return; // Geçersiz koordinatlar

    buffer = (int *)fractol->pointer_to_image;
    if (!buffer)
    {
        fprintf(stderr, "Error: pointer_to_image is NULL\n");
        return;
    }

	buffer[(y * fractol->size_line / 4) + x] = color;
}