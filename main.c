/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:06 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 15:58:07 by fkuyumcu         ###   ########.fr       */
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

int	exit_fractal(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->window);
	free(fractol->mlx);
	free(fractol);
	exit(1);
	return (0);
}

int	key_hook(int key_code, t_fractol *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == LEFT)
		fractal->off_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->off_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->off_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->off_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractol(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	/* else if (key_code == J)
		set_random_julia(&fractal->cx, &fractal->cx);
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code); */
	draw(fractal, "mbrot");
	return (0);
}







 int main(int argc, char **argv) // Julia şimdilik argüman almıyor
{
    t_fractol *fractol;
	
//-Wall-Wextra -Werror!!!!!!

    fractol = malloc(sizeof(t_fractol));
    if ((argc == 2 && !ft_strncmp(argv[1], "mbrot", 5)) ||
        (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
    {
        init_fractol(fractol);
        draw(fractol, argv[1]);

    	mlx_key_hook(fractol->window, key_hook, fractol);
		//mlx_mouse_hook(fractal->window, mouse_hook, fractal);
		mlx_hook(fractol->window, 17, 0L, exit_fractal, fractol);
        mlx_loop(fractol->mlx);
    }
    else
    {

    }
    return (0);
}
 

