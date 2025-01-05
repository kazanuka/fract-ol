/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vangogh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:44:05 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 17:51:51 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_draw(void *ptr)
{
	t_fractol	*fractol;
	int			num1;
	int			num2;
	
	fractol = (t_fractol*)ptr;
    fractol->x = 0;
	fractol->y = 0;
	
	while(fractol->x < SIZE)
	{
		while(fractol->y < SIZE)
		{
			calc_julia(fractol);
			(fractol->y)++;	
		}
		(fractol->y) = 0;
		(fractol->x)++;
	}
}


void	mbrot_draw(void *fractol_void)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)fractol_void;
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			calc_mbrot(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}
void draw(t_fractol *fractol, char *prompt)
{
    fractol->name = prompt;

    if (ft_strncmp(prompt, "mbrot", 5) == 0)
		mbrot_draw(fractol);
    else if (ft_strncmp(prompt, "julia", 5) == 0)
        julia_draw(fractol);
    mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}