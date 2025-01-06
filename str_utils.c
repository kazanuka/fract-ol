/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuyumcu <fkuyumcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:37:21 by fkuyumcu          #+#    #+#             */
/*   Updated: 2025/01/06 15:26:14 by fkuyumcu         ###   ########.fr       */
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



static void	ft_set_var(int *a, double *result,
		double *fraction, int *fractionDigits)
{
	*a = 0;
	*result = 0.0;
	*fraction = 0.0;
	*fractionDigits = 0;
}

static void	ft_pow(double *fraction, int *fractiondigits,
									int a, const char *str)
{
	if (str[a] == '.')
	{
		a++;
		while (str[a] >= '0' && str[a] <= '9')
		{
			*fraction = *fraction * 10.0 + (str[a] - '0');
			*fractiondigits += 1;
			a++;
		}
	}
}

double	ft_atod(const char *str)
{
	int		a;
	int		flag;
	double	result;
	double	fraction;
	int		fractiondigits;

	ft_set_var(&a, &result, &fraction, &fractiondigits);
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			flag = -1;
		else
			flag = 1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = result * 10.0 + (str[a] - '0');
		a++;
	}
	ft_pow(&fraction, &fractiondigits, a, str);
	result += fraction / pow(10, fractiondigits);
	return (result * flag);
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

