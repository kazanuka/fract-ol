/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:06 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 18:20:33 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Julia and Mandelbrot Sets

Sonsuz Zoom
cla ile hangi fraktali kullanacağımızı seçmeliyiz
juliayı şekillendirmek için x y koordinatlarını command line ile alabilmeliyiz
esc pencereyi kapatmalı
click on the x window, closes process leaks free


*/

#include "minilibx-linux/mlx.h"
#include "fractol.h"

  int main(int argc, char **argv) // Julia şimdilik argüman almıyor
{
    t_fractol *fractol;
	
//-Wall-Wextra -Werror!!!!!!
//Error var

    fractol = malloc(sizeof(t_fractol));
	if(!fractol)
		exit(EXIT_FAILURE);
    if ((argc == 2 && !ft_strncmp(argv[1], "mbrot", 5)) ||
        (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        init_fractol(fractol);
        if(argc == 4)
        {
            fractol->jul_x = ft_atod(argv[2]);
            fractol->jul_y = ft_atod(argv[2]);
            draw(fractol, argv[1]);
        }
        else
            draw(fractol, argv[1]);
    	mlx_key_hook(fractol->window, key_hook, fractol);
		mlx_mouse_hook(fractol->window, mouse_hook, fractol);
		mlx_hook(fractol->window, 17, 0L, exit_fractal, fractol);
        mlx_loop(fractol->mlx);
    }
    else
    {

    }
    return (0);
} 
 

