/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:17:06 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/07 13:06:38 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!fractol)
		exit(EXIT_FAILURE);
	check_args(argc, argv, fractol);
	init_fractol(fractol);
	if (argc == 4)
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
	free(fractol);
	return (0);
}
