/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vangogh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:44:05 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 11:54:32 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_draw(void *ptr)
{
    
}


void    mbrot_draw(void *ptr)
{
    t_fractol *fractol;
    fractol = ptr;
    while(fractol->x < SIZE)
    {
        while(fractol->y < SIZE)
        {
            calc_mbrot(fractol);       
            (fractol->y)++;
        }
        (fractol->y) = 0;
        (fractol->x)++;
    }
}

draw(t_fractol *fractol, char *prompt)
{
    if(ft_strncmp(prompt,"mbrot",5) == 0)
        mbrot_draw(fractol);   
    else if(ft_strncmp(prompt,"julia",5) == 0)
        julia_draw(fractol);
    
}