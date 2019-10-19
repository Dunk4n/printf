/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:52:12 by niduches          #+#    #+#             */
/*   Updated: 2019/10/19 16:12:29 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libftprintf.h"

static int		conv_percent(va_list list, int *flags)
{
	long long		c;
	char			padding;
	size_t			i;

	(void)list;
	c = '%';
	padding = (!flags[0] && flags[1]) ? '0' : ' ';
	if (flags[0])
		write(1, &c, 1);
	i = 0;
	while (flags[10] && (int)i < flags[10] - 1)
	{
		write(1, &padding, 1);
		i++;
	}
	if (!flags[0])
		write(1, &c, 1);
	return (i + 1);
}

int				ft_makeconv(const char *str, int *size, va_list list)
{
	size_t	i;
	int		res;
	int		(*f[9])(va_list, int*) = {conv_char, conv_str, conv_ptr, conv_int,
conv_int, conv_uint, conv_hex, conv_uhex, conv_percent};
	int		flags[NB_FLAGS + 1];

	i = 0;
	while (i <= NB_FLAGS)
		flags[i++] = 0;
	flags[2] = -1;
	get_flags(flags, str + 1, *size - 2, list);
	i = 0;
	res = 0;
	while (CONVERSIONS[i])
	{
		if (CONVERSIONS[i] == str[*size - 1])
		{
			res = (f[i])(list, flags);
			break ;
		}
		i++;
	}
	if (res == -1)
		*size = -1;
	return (res);
}

//- reverse indent
//[1 .. 9] indent
//0 padding
//The precision within a string format specifies the maximum field width.
//	%4.8s
//Specifies a minimum width of 4 and a maximum width of 8 characters. If the string is greater than 8 characters, it will be cropped down to size.
//+ Sign of number always O/P
//' ' Positive values begin with a blank
//# Various uses https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
//' ?
//h or hh %2
//* = nbr next arg
