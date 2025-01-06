/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:37:21 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 19:22:09 by fkuyumcu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}



static const char *parser(const char *str, int *sign)
{
    *sign = 1;
    while (*str == ' ' || *str == '\t' || *str == '\n' ||
           *str == '\r' || *str == '\v' || *str == '\f')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            *sign = -1;
        str++;
    }
    return str;
}

static double parse_int(const char *str, double *fraction, double *divisor)
{
    double result;

	result = 0.0;
	*fraction = 0.0;
	*divisor = 1.0;

    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }

    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            *fraction = *fraction * 10.0 + (*str - '0');
            *divisor *= 10.0;
            str++;
        }
    }

    return (result);
}

double ft_atod(const char *str)
{
    double result, fraction, divisor;
    int sign;
    str = parser(str, &sign);
    result = parse_int(str, &fraction, &divisor);
    result += fraction / divisor;
    return (result * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		++s;
	}
}

