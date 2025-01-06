/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:06 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 15:18:57 by fkuyumcu         ###   ########.fr       */
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
//Makefile düzenle
//Make re
//Tuşları düzenle
//Leakleri hallet
//zoom ve öteleme mantığına iyi çalış
//printf çıkart


    fractol = malloc(sizeof(t_fractol));
    fractol->t = 0;
    if(!fractol)
	    exit(EXIT_FAILURE);
    init_fractol(fractol);
    check_args(argc,argv,fractol);
    if(argc == 4)
    {
        fractol->jul_x = ft_atod(argv[2]);
        fractol->jul_y = ft_atod(argv[3]);
        draw(fractol, argv[1]);
    }
    else
        draw(fractol, argv[1]);
    mlx_key_hook(fractol->window, key_hook, fractol);
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	mlx_hook(fractol->window, 17, 0L, exit_fractal, fractol);
    mlx_loop(fractol->mlx);
    return (0);
} 
 

