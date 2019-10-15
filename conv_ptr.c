/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pointeur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:08:54 by niduches          #+#    #+#             */
/*   Updated: 2019/10/14 14:23:13 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>
#include "libft.h"

static void		display_hex(long ptr, int size)
{
	char	res[13];
	size_t	i;

	if (!ptr)
	{
		write(1, "0", 1);
		return ;
	}
	res[size] = '\0';
	i = 0;
	while (ptr)
	{
		i++;
		res[--size] = HEX[ptr % 16];
		ptr /= 16;
	}
	write(1, res, i);
}

static size_t	display_ptr(long ptr, int min)
{
	int		i;
	int		size;
	long	tmp;

	write(1, "0x", 2);
	i = 0;
	min -= 2;
	tmp = ptr;
	size = 1;
	while (tmp /= 16)
		size++;
	while (i < min - size)
	{
		write(1, "0", 1);
		i++;
	}
	display_hex(ptr, size);
	return (i);
}

static size_t	size_ptr(long ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (3);
	while (ptr /= 16)
		i++;
	return (i + 2);
}

size_t			conv_ptr(va_list list, int *flags)
{
	void	*ptr;
	size_t	i;

	if (flags[2] >= 0 || flags[0])
		flags[1] = 0;
	ptr = va_arg(list, void*);
	i = size_ptr((long)ptr);
	if (flags[0])
		i += display_ptr((long)ptr, flags[2] + 2);
	while (!flags[1] && i < flags[10])
	{
		write(1, " ", 1);
		i++;
	}
	if (!flags[0])
	{
		if (flags[1])
			i += display_ptr((long)ptr, flags[10]);
		else
			i += display_ptr((long)ptr, flags[2] + 2);
	}
	return (i);
}
