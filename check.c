/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:14:58 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 18:13:35 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

 static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

static	int ft_isnum(const char *str) {
    int i = 0;
    int has_decimal = 0;

    if (str == NULL || *str == '\0') {
        return 0;
    }
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] == '.') {
            if (has_decimal) {
                return 0;  
            }
            has_decimal = 1; 
        } else if (!ft_isdigit((unsigned char)str[i])) {
            return 0; 
        }
        i++;
    }
    return 1; 
} 

 void err_fractol(t_fractol *fractol)
{
	ft_putstr_fd("Usage:\n ./fractol mbrot OR ./fractol julia OR ./fractol julia <val1> <val2>\n",1);
	ft_putstr_fd("Use '.' as decimal seperator. Please use only ONE decimal seperator.\n",1);
	free(fractol);
	exit(1); 
} 

void    check_args(int argc, char **argv, t_fractol *fractol)
{
   if (!((argc == 2 && !ft_strncmp(argv[1], "mbrot", 5)) ||
        (argc == 4 && !ft_strncmp(argv[1], "julia", 5)) ||
        (argc == 2 && !ft_strncmp(argv[1], "julia", 5))))
        err_fractol(fractol);
    if (argc > 4 || argc < 2 || argc == 3)
        err_fractol(fractol);
    if (argc == 4 && ft_strncmp(argv[1],"julia",5))
        err_fractol(fractol);
    if (argc == 4 && ((!ft_isnum(argv[2])) || (!ft_isnum(argv[3]))))
        err_fractol(fractol);
} 