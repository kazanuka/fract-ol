/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vangogh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:44:05 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 11:48:59 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

mbrot_draw(void *ptr)
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

