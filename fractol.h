/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:34:48 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/05 17:24:27 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>
#define ERR "Please enter ./fractol mandelbrot or ./fractol julia <value 1> <value 2>"
#define SIZE 900.0

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5




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

int		ft_atoi(const char *str);
int		mouse_hook(int mouse, int x, int y, t_fractol *fractol);
int		exit_fractal(t_fractol *fractol);
int		key_hook(int key_code, t_fractol *fractol);
void	paint(int x, int y, t_fractol *fractol, int color);
void	calc_mbrot(t_fractol *fractol);
void	calc_julia(t_fractol *fractol, int val1, int val2);
void    init_fractol(t_fractol *fractal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*mbrot_draw(void *ptr);
void    draw(t_fractol *fractol, char *prompt, char *val1, char *val2);
void	julia_draw(void *ptr, char *val1, char *val2);
#endif