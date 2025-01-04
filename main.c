/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:06 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/04 18:42:01 by fkuyumcu         ###   ########.fr       */
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
  int main(int argc, char **argv)//julia şimdilik argüman almıyor
{
    t_fractol *fractol;
    fractol = malloc(sizeof(t_fractol));
    if(argc == 2 && !ft_strncmp(argv[1],"mbrot",5)
    || argc == 4 && !ft_strncmp(argv[1],"julia",5))
    {
        init_fractol(fractol);
        init_mlx(fractol);
        draw(fractol,argv[1]);
        
        mlx_loop(fractol->mlx);
        
            
    }
    else
    {

        
    }


    
} 

