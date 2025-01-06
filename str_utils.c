/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:37:21 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 17:38:55 by fkuyumcu         ###   ########.fr       */
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



double ft_atod(const char *str)
{
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 1.0;
    int sign = 1;

    // Boşlukları atla
    while (*str == ' ' || *str == '\t' || *str == '\n' ||
           *str == '\r' || *str == '\v' || *str == '\f')
        str++;

    // İşareti kontrol et
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Tam kısmı işle
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }

    // Ondalık kısmı işle
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            fraction = fraction * 10.0 + (*str - '0');
            divisor *= 10.0;
            str++;
        }
    }

    // Tam ve ondalık kısmı birleştir
    result += fraction / divisor;
	/* if(result  __DBL_MAX__)
	{
		exit(1);
	} */
    // İşareti uygula
    return result * sign;
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

