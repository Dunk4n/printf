/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:52:12 by niduches          #+#    #+#             */
/*   Updated: 2019/10/13 16:51:53 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

size_t		ft_makeconv(const char *str, size_t size, va_list list)
{
	size_t	i;
	size_t	res;
	size_t	(*f[9])(va_list, char, int*) = {};
	int		flags[NB_FLAGS + 1];

	i = 0;
	while (i <= NB_FLAGS)
		flags[i++] = 0;
	get_flags(flags, str + 1, size - 2, list);
	i = 0;
	res = 0;
	while (CONVERSIONS[i])
	{
		if (CONVERSIONS[i] == str[size - 1])
		{
			//res = (*f)(list, str[size - 1], flags);
			break ;
		}
		i++;
	}
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
