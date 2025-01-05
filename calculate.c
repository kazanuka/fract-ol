/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:27:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 11:43:23 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mbrot(t_fractol *fractol)
{
    int		i;
    double	tmp;
	fractol->zx = 0;
	fractol->zy = 0;
	fractol->name = "mbrot";
	fractol->cx = fractol->x;//zoom ekle
	fractol->cy	= fractol->y;
	while(++i < fractol->max_iterations)
	{
		tmp = (fractol->zx) * (fractol->zx) - (fractol->zy) * (fractol->zy) + (fractol->cx);
		(fractol->zy) = 2 * (fractol->zx) * (fractol->zy) + fractol->cy;
		(fractol->zx) = tmp;
		if(fractol->zx * fractol->zx + fractol->zy * fractol->zy >= __DBL_MAX__ )
			break;
	}
	if(i == (fractol->max_iterations))
		paint((fractol->x),(fractol->y),fractol,0x000000);
	else
		paint((fractol->x),(fractol->y),fractol,(fractol->color)*i);
}

void	paint(int x, int y, t_fractol *fractol, int color)//	bu fonksiyona iyi bak
{
	int	*buffer;

	buffer = fractol->pointer_to_image;
	buffer[(y * fractol->size_line / 4) + x] = color;
}