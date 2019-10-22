/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:21:33 by niduches          #+#    #+#             */
/*   Updated: 2019/10/22 14:03:44 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>
#include "libftprintf.h"

static size_t	put_double(double nb, int len, int *flags)
{
	size_t	i;
	int		j;
	char	c;

	i = put_long_nbr((long long)nb, len);
	if (flags[2])
		i += write(1, ".", 1);
	else
		return (i);
	nb = nb - (long long)nb;
	if (flags[2] == -1)
		flags[2] = 6;
	j = 0;
	if (nb < 0)
		nb *= -1;
	while (j < flags[2])
	{
		nb *= 10;
		c = (char)(nb) + '0';
		i += write(1, &c, 1);
		nb = nb - (long long)(nb);
		j++;
	}
	return (i);
}

static size_t	put_nb(double nb, int *flags)
{
	size_t	i;

	i = 0;
	if (nb < 0)
		i += write(1, "-", 1);
	if (nb >= 0 && flags[9])
		i += write(1, "+", 1);
	if (nb >= 0 && flags[8] && !flags[9])
		i += write(1, " ", 1);
	if (!flags[2] && !nb)
		return (i);
	if (flags[1])
	{
		i =
put_double(nb, flags[10] - i - ((flags[2] == -1) ? 7 : flags[2]), flags) + i;
		return (i);
	}
	return (put_double(nb, 0, flags) + i);
}

static size_t	get_len(double nb, int *flags)
{
	int	len;
	int add;

	if (flags[0])
		return (0);
	len = 1;
	add = 0;
	if (nb < 0 || flags[8] || flags[9])
		add++;
	if (!flags[2] && !nb)
		return (add);
	while ((long long)(nb / 10))
	{
		nb /= 10;
		len++;
	}
	if (flags[2] == -1)
		add += 7;
	else
		add += flags[2] + ((flags[2] == 0) ? 0 : 1);
	return (len + add);
}

static double	float_round(double nb, int *flags)
{
	double	dec;
	double	tmp;
	size_t	i;
	size_t	len;

	tmp = nb;
	dec = (nb < 0) ? -1 : 1;
	len = 0;
	i = (flags[2] == -1) ? 6 : flags[2];
	while (len++ < i)
	{
		tmp *= 10;
		dec /= 10;
	}
	if ((float)(tmp - (long long)tmp) > 0.5 ||
(float)(tmp - (long long)tmp) < -0.5)
		nb += dec;
	return (nb);
}

int				conv_float(va_list list, int *flags)
{
	double	nb;
	size_t	i;
	size_t	len;

	if (flags[0])
		flags[1] = 0;
	nb = float_round(va_arg(list, double), flags);
	i = 0;
	len = get_len(nb, flags);
	if (flags[0])
		i += put_nb(nb, flags);
	while (!flags[1] && (int)(i++) < (int)(flags[10] - len))
		write(1, " ", 1);
	if (!flags[0])
		i += put_nb(nb, flags);
	return (i + ((!flags[1]) ? -1 : 0));
}
