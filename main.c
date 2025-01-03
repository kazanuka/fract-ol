/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:06 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/03 18:47:12 by fkuyumcu         ###   ########.fr       */
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

//Mandelbrot Set: z = z^2 + c
//Julia Set:  
#include "fractol.h"
int main(int argc, char **argv)
{
    if(argc == 2 && !ft_strncmp(argv[1],"mandelbrot",10)
    || argc == 4 && !ft_strncmp(argv[1],"julia",5))
    {

            
    }
    else
    {

        
    }


    
}