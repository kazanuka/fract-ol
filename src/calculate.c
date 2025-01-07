/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:27:16 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/07 12:58:30 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mbrot(t_fractol *fractol)
{
	int		i;
	double	x_temp;

	fractol->name = "mbrot";
	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->off_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->off_y;
	while (++i < fractol->max_iterations)
	{
		x_temp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_temp;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		paint(fractol->x, fractol->y, fractol, 0);
	else
		paint(fractol->x, fractol->y, fractol, fractol->color * i);
}

void	calc_julia(t_fractol *fractol)
{
	int		i;
	double	tmp;

	fractol->name = "julia";
	i = 0;
	fractol->cx = fractol->jul_x;
	fractol->cy = fractol->jul_y;
	fractol->zx = (fractol->x / fractol->zoom) + fractol->off_x;
	fractol->zy = (fractol->y / fractol->zoom) + fractol->off_y;
	while (++i < fractol->max_iterations)
	{
		tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = tmp;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		paint((fractol->x), (fractol->y), fractol, 0);
	else
		paint((fractol->x), (fractol->y), fractol, (fractol->color) * i);
}

void	paint(int x, int y, t_fractol *fractol, int color)
{
	int	*tmp;

	tmp = (int *)fractol->img_ptr;
	tmp[(y * fractol->size_line / 4) + x] = color;
}
