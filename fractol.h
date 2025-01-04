/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:34:48 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/04 18:27:17 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

#define ERR "Please enter ./fractol mandelbrot or ./fractol julia <value 1> <value 2>"
#define SIZE 900

typedef struct s_fractol
{
    void	*mlx;
	void	*window;
	void	*img;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	off_x;
	double	off_y;
	double	zoom;
	char	*name;
	int		max_iterations;    
}   t_fractol;


void	put_color(int x, int y, t_fractol *fractol, int color);
void	calc_mbrot(t_fractol *fractol);
void    init_fractol(t_fractol *fractol);
void    init_mlx(t_fractol *fractol);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	mbrot_draw(void *ptr);

#endif