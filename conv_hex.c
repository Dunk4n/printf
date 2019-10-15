/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:38:21 by niduches          #+#    #+#             */
/*   Updated: 2019/10/14 19:52:05 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

static unsigned long long	get_nb(va_list list, int *flags)
{
	if (flags[4] == 1)
		return (va_arg(list, unsigned long));
	if (flags[4] == 2)
		return (va_arg(list, unsigned long long));
	if (flags[5] == 1)
		return ((unsigned short)va_arg(list, unsigned int));
	if (flags[5] == 2)
		return ((unsigned char)va_arg(list, unsigned int));
	return (va_arg(list, unsigned int));
}

static size_t				put_long_nbr(unsigned long long nb, int len)
{
	size_t	n;
	char	c;

	n = 0;
	if (nb > 15 || len - 1 > 0)
	{
		n += put_long_nbr(nb / 16, len - 1);
		c = HEX[nb % 16];
		n += write(1, &c, 1);
		return (n);
	}
	c = HEX[nb];
	n += write(1, &c, 1);
	return (n);
}

static size_t				put_nb(unsigned long long nb, int *flags)
{
	if (flags[1])
		return (put_long_nbr(nb, flags[10]));
	else
		return (put_long_nbr(nb, flags[2]));
}

static size_t				get_len(unsigned long long nb, int *flags)
{
	int	len;

	if (flags[0])
		return (0);
	len = 1;
	while (nb /= 16)
		len++;
	if (flags[2] != -1)
		return ((len < flags[2]) ? flags[2] : len);
	return (len);
}

size_t			conv_hex(va_list list, int *flags)
{
	unsigned long long	nb;
	size_t				i;
	size_t				len;

	if (flags[2] >= 0 || flags[0])
		flags[1] = 0;
	nb = get_nb(list, flags);
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
