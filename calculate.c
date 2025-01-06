/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:27:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 13:38:35 by fkuyumcu         ###   ########.fr       */
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
		paint(fractal->x,fractal->y,fractal,0);
	else
		paint(fractal->x,fractal->y,fractal,fractal->color *i);
}

void	calc_julia(t_fractol *fractol)
{
    int  i;
 	double tmp;

 	fractol->name = "julia";
 	fractol->cx = fractol->jul_x;
 	fractol->cy = fractol->jul_y;
 	fractol->zx = fractol->x / fractol->zoom + fractol->off_x;
 	fractol->zy = fractol->y / fractol->zoom + fractol->off_y;
 	i = 0;
 	while (++i < fractol->max_iterations)
 	{
  	tmp = fractol->zx;
  	fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
   	+ fractol->cx;
  	fractol->zy = 2 * fractol->zy * tmp + fractol->cy;
  	if (fractol->zx * fractol->zx + fractol->zy
   	* fractol->zy >= __DBL_MAX__)
   break ;
 	}
 	if (i == fractol->max_iterations)
  	paint(fractol->x , fractol->y, fractol, 0x000000);
	 else
  	paint(fractol->x, fractol->y, fractol, (fractol->color * i));
    
}


void	paint(int x, int y, t_fractol *fractol, int color)//	bu fonksiyona iyi bak
{
	int	*buffer;

    buffer = (int *)fractol->pointer_to_image;
	buffer[(y * fractol->size_line / 4) + x] = color;
}