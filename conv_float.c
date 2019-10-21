/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:21:33 by niduches          #+#    #+#             */
/*   Updated: 2019/10/21 15:54:27 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>
#include "libftprintf.h"

static size_t	put_long_nbr(long long nb, int len)
{
	size_t	n;
	char	c;

	n = 0;
	if (nb > 9 || nb < -9 || len - 1 > 0)
	{
		n += put_long_nbr((nb < 0) ? (-(nb / 10)) : (nb / 10), len - 1);
		c = ((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0';
		n += write(1, &c, 1);
		return (n);
	}
	c = ((nb < 0) ? (-nb) : nb) + '0';
	n += write(1, &c, 1);
	return (n);
}

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
	while (j < flags[2])
	{
		nb *= 10;
		c = (int)nb + '0';
		i += write(1, &c, 1);
		nb = nb - (int)nb;
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
		return (put_double(nb, flags[10] - i - ((flags[2] == -1) ? 7 : flags[2]),
flags) + i);
	return (put_double(nb, 0, flags) + i);
	//else
	//	return (put_double(nb, flags[2], flags) + i);
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

int				conv_float(va_list list, int *flags)
{
	double	nb;
	size_t	i;
	size_t	len;

	if (flags[0])
		flags[1] = 0;
	nb = va_arg(list, double);
	i = 0;
	len = get_len(nb, flags);
	if (flags[0])
		i += put_nb(nb, flags);
	while (!flags[1] && (int)i < (int)(flags[10] - len))
	{
		write(1, " ", 1);
		i++;
	}
	if (!flags[0])
		i += put_nb(nb, flags);
	return (i);
}
