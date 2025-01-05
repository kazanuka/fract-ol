/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:27:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 12:52:19 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mbrot(t_fractol *fractol)
{
    int		i = 0;
    double	tmp;

    fractol->zx = 0;
    fractol->zy = 0;
    fractol->cx = fractol->off_x + ((fractol->x / (double)SIZE) * 3.0);
    fractol->cy = fractol->off_y + ((fractol->y / (double)SIZE) * 3.0);

    while (i < fractol->max_iterations)
    {
        tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy + fractol->cx;
        fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
        fractol->zx = tmp;
        if (fractol->zx * fractol->zx + fractol->zy * fractol->zy >= 4.0)
            break;
        i++;
    }
    if (i == fractol->max_iterations)
        paint(fractol->x, fractol->y, fractol, 0x000000); // Siyah
    else
        paint(fractol->x, fractol->y, fractol, fractol->color * (i % 256));
}

void	paint(int x, int y, t_fractol *fractol, int color)//	bu fonksiyona iyi bak
{
	int	*buffer;

	buffer = fractol->pointer_to_image;
	buffer[(y * fractol->size_line / 4) + x] = color;
}