/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:32:16 by niduches          #+#    #+#             */
/*   Updated: 2019/10/14 18:45:16 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>
#include "libft.h"

static long long	get_char(va_list list, int *flags)
{
	if (flags[4] == 1)
		return ((wint_t)va_arg(list, wint_t));
	if (flags[4] == 2)
		return (va_arg(list, unsigned long long));
	if (flags[5] == 1)
		return ((unsigned short)va_arg(list, int));
	if (flags[5] == 2)
		return ((unsigned char)va_arg(list, int));
	return ((unsigned char)va_arg(list, int));
}

size_t				conv_char(va_list list, int *flags)
{
	long long		c;
	char			padding;
	size_t			i;

	c = get_char(list, flags);
	padding = (!flags[0] && flags[1]) ? '0' : ' ';
	if (flags[0])
		write(1, &c, 1);
	i = 0;
	while (flags[10] && i < flags[10] - 1)
	{
		write(1, &padding, 1);
		i++;
	}
	if (!flags[0])
		write(1, &c, 1);
	return (i + 1);
}
