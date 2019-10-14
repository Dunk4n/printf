/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:09:48 by niduches          #+#    #+#             */
/*   Updated: 2019/10/13 22:56:46 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <wchar.h>
#include "libft.h"

static char	*get_str(va_list list, int *flags)
{
	/*
	   if (flags[4] == 1)
	   return ((char*)(wchar_t)va_arg(list, char*));
	   if (flags[4] == 2)
	   return ((char*)(long long)va_arg(list, char*));
	   if (flags[5] == 1)
	   return ((char*)(short)va_arg(list, char*));
	   if (flags[5] == 2)
	   return ((char*)(int)va_arg(list, char*));
	   */
	return (va_arg(list, char*));
}

size_t		conv_str(va_list list, int *flags)
{
	char	*s;
	char	padding;
	size_t	i;
	size_t	len;

	s = get_str(list, flags);
	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	flags[2] = (len < flags[2]) ? len : flags[2];
	padding = (!flags[0] && flags[1]) ? '0' : ' ';
	if (flags[0])
		write(1, s, flags[2]);
	i = 0;
	while ((int)(flags[10] - flags[2]) > 0 && i < (int)(flags[10] - flags[2]))
	{
		write(1, &padding, 1);
		i++;
	}
	if (!flags[0])
		write(1, s, (len < flags[2]) ? len : flags[2]);
	return (i + ((len < flags[2]) ? len : flags[2]));
}
