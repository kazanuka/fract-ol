/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vangogh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:44:05 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 17:24:46 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_draw(void *ptr, char *val1, char *val2)
{
	t_fractol	*fractol;
	int	num1;
	int	num2;
	
	fractol = (t_fractol*)ptr;
    fractol->x = 0;
	fractol->y = 0;
	num1 = ft_atoi(val1);
	num2 = ft_atoi(val2);
	
	while(fractol->x < SIZE)
	{
		while(fractol->y < SIZE)
		{
			calc_julia(fractol, num1, num2);
			
		}
	}
}


void	*mbrot_draw(void *fractol_void)
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
	return (NULL);
}
void draw(t_fractol *fractol, char *prompt, char *val1, char*val2)
{
    fractol->name = prompt;

    if (ft_strncmp(prompt, "mbrot", 5) == 0)
		mbrot_draw(fractol);
    else if (ft_strncmp(prompt, "julia", 5) == 0)
        julia_draw(fractol,val1,val2);
    mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->img, 0, 0);
}